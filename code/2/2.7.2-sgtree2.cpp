ll n, a[N];
namespace sg{
    struct Q{ // 存修改，存 tag
        ll tag;
        Q(ll tag=0): tag(tag){} // 注意初始值
        void operator+=(const Q &q){ tag+=q.tag; }
            // tag 的叠加
    };
    struct P{ // 存记录维护的答案
        ll sum;
        P(ll sum=0): sum(sum){} // 注意初始值
        void push(const Q &q, int l, int r){ sum+=q.tag*(r-l+1); }
            // 区间从操作更新答案
        void init(int x){ sum=a[x]; } // 建树中的赋值
    };
    P operator&(const P &a, const P &b){ // 子区间合并答案
        return P(a.sum+b.sum);
    }
    // 基本上只需要修改上面的部分
    P p[N<<2];
    Q q[N<<2];
#define lson o*2, l, (l+r)/2
#define rson o*2+1, (l+r)/2+1, r
    void up(int o, int l, int r){
        if(l<r) p[o]=p[o*2]&p[o*2+1];
    }
    void push(const Q &v, int o, int l, int r){
        q[o]+=v;
        p[o].push(v, l, r);
    }
    void down(int o, int l, int r){
        push(q[o], lson); push(q[o], rson);
        q[o]=Q();
    }
    void build(int o=1, int l=1, int r=n){
        if(l==r) p[o].init(l);
        else{ build(lson); build(rson); }
        up(o, l, r);
    }
    P query(int ql, int qr, int o=1, int l=1, int r=n){
        if(ql>r||l>qr) return P();
        if(ql<=l&&r<=qr) return p[o];
        down(o, l, r);
        return query(ql, qr, lson)&query(ql, qr, rson);
    }
    void update(int ql, int qr, const Q& v, int o=1, int l=1, int r=n){
        if(ql>r||l>qr) return;
        if(ql<=l&&r<=qr){ push(v, o, l, r); return; }
        down(o, l, r);
        update(ql, qr, v, lson); update(ql, qr, v, rson);
        up(o, l, r);
    }
}
using namespace sg;