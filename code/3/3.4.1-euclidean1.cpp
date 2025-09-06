ll floordiv(ll x, ll y){
    assert(y!=0);
    if(y<0) x=-x;
    return x>=0?(x/y):((x-y+1)/y);
}

ll mod(ll x, ll y){ return (x%y+y)%y; }

ll f(ll a, ll b, ll c, ll n){
    if(c<0) a=-a, b=-b, c=-c;
    assert(c!=0);
    ll res=(floordiv(a, c)%MOD+MOD)%MOD*((n*(n+1)/2)%MOD)%MOD
          +(floordiv(b, c)%MOD+MOD)%MOD*(n+1)%MOD;
    res%=MOD;
    a=mod(a, c), b=mod(b, c);
    if(!a) return res;
    res+=(n+1)*(floordiv(a*n+b, c)%MOD)%MOD-floordiv(b, a)%MOD;
    res=(res%MOD+MOD)%MOD;
    res-=f(c, a-b-1, a, floordiv(a*n+b, c));
    res=(res%MOD+MOD)%MOD;
    return res;
}