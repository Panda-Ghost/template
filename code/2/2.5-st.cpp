ll n, a[N], st[N][SP+10], to[N][SP+10], l2g[N];
ll op(ll x, ll y){ return max(x, y); }

void init(){
    l2g[1]=0, to[n+1][0]=n+1;
    REP(i, 2, n) l2g[i]=l2g[i-1]+!(i&(i-1));
    REP(i, 1, n) st[i][0]=a[i], to[i][0]=i+1;
    REP(i, 1, SP){
        REP(j, 1, n){
            to[j][i]=to[to[j][i-1]][i-1];
            st[j][i]=op(st[j][i-1], st[to[j][i-1]][i-1]);
        }
    }
}

ll query(ll l, ll r){ // [l, r] 闭区间
    ++r;
    ll d=l2g[r-l];
    return op(st[l][d], st[r-(1<<d)][d]);
}