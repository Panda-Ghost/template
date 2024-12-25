struct node{
    int l, r;
    mutable int v; 
    bool operator<(const node& rhs) const { return l<rhs.l; } 
};

set<node> odt;
typedef set<node>::iterator iter;

iter split(ll p){
    iter tmp=odt.lower_bound((node){p, 0, 0});
    if(tmp!=odt.end()&&tmp->l==p) return tmp;
    --tmp;
    int tl=tmp->l, tr=tmp->r, tv=tmp->v;
    odt.erase(tmp);
    odt.insert((node){tl, p-1, tv});
    return odt.insert((node){p, tr, tv}).first;
}

// 修改和查询注意 split 顺序
// iter itr=split(r+1), itl=split(l);