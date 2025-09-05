struct mat{
    ll n, m;
    vector<vector<ll>> val; // 注意下标从 0 开始
    mat(ll _n, ll _m): n(_n), m(_m){
        val.resize(_n);
        REP(i, 0, _n-1) val[i].resize(_m, 0); 
    }
    mat(ll _n, ll _m, vector<vector<ll>> _val):
        n(_n), m(_m), val(_val){}
};

mat mul(const mat& x, const mat& y, ll mod){
    assert(x.m==y.n);
    mat res(x.n, y.m);
    REP(i, 0, res.n-1) REP(j, 0, res.m-1){
        REP(k, 0, x.m-1){
            res.val[i][j]=(res.val[i][j]+x.val[i][k]*y.val[k][j]%mod)%mod;
        }
    }
    return res;
}

mat qpow(mat a, ll x, ll mod){
    assert(a.n==a.m);
    mat res(a.n, a.n);
    REP(i, 0, a.n-1) res.val[i][i]=1;
    REP(i, 0, a.n-1) REP(j, 0, a.m-1) a.val[i][j]%=mod;
    while(x){
        if(x&1) res=mul(res, a, mod);
        a=mul(a, a, mod), x>>=1;
    }
    return res;
}