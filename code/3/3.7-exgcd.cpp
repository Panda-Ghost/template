ll exgcd(ll a, ll b, ll &x, ll &y){
    if(b==0){
        x=1, y=0;
        return a;
    }
    ll xx=0, yy=0;
    ll res=exgcd(b, a%b, xx, yy);
    y=xx-(a/b)*yy, x=yy;
    return res;
}

ll inv(ll x, ll mod){
    ll xx, yy;
    ll d=exgcd(x, mod, xx, yy);
    assert(d==1);
    return (xx%mod+mod)%mod;
}