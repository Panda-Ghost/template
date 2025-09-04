ll n, fwt[N];
ll prod(ll x, ll d){ return x+d; }
ll op(ll x, ll y){ return x+y; }

void edit(int x, ll d){
    for(; x<=n; x+=x&-x) fwt[x]=prod(fwt[x], d);
}

ll query(int x){
    assert(1<=x&&x<=n);
    ll res=fwt[x]; x-=x&-x;
        // 这种写法不用考虑最大或最小值的初值问题
    for(; x; x-=x&-x) res=op(res, fwt[x]);
    return res;
}
