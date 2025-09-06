ll n, a[N];
struct seg{
    int l, r;
    ll sum, tag;
}s[N<<2];
#define lson (o*2)
#define rson (o*2+1)

void down(int o){
    if(s[o].tag){
        s[lson].sum+=s[o].tag*(s[lson].r-s[lson].l+1), s[lson].tag+=s[o].tag;
        s[rson].sum+=s[o].tag*(s[rson].r-s[rson].l+1), s[rson].tag+=s[o].tag;
        s[o].tag=0;
    }
}

void build(int o, int l, int r){
    s[o].l=l, s[o].r=r;
    if(l==r) return s[o].sum=a[l], void();
    int mid=(l+r)/2;
    build(lson, l, mid);
    build(rson, mid+1, r);
    s[o].sum=s[lson].sum+s[rson].sum;
}

void add(int o, int l, int r, ll d){
    if(l<=s[o].l&&s[o].r<=r)
        return s[o].sum+=d*(s[o].r-s[o].l+1), s[o].tag+=d, void();
    down(o);
    int mid=(s[o].l+s[o].r)/2;
    if(l<=mid) add(lson, l, r, d);
    if(r>mid) add(rson, l, r, d);
    s[o].sum=s[lson].sum+s[rson].sum;
}

ll sum(int o, int l, int r){
    if(l<=s[o].l&&s[o].r<=r)
        return s[o].sum;
    down(o);
    int mid=(s[o].l+s[o].r)/2; ll res=0;
    if(l<=mid) res+=sum(lson, l, r);
    if(r>mid) res+=sum(rson, l, r);
    return res;
}