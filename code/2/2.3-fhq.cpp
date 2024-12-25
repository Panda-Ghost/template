int n, m, clk, rt;
struct node{
    int key, val, sz, tag, ls, rs;
}t[N];
int newnode(int k){ return t[++clk]=(node){k, rand(), 1, 0}, clk; }
void down(int o){
    if(t[o].tag){
        t[t[o].ls].tag=1-t[t[o].ls].tag;
        t[t[o].rs].tag=1-t[t[o].rs].tag;
        swap(t[t[o].ls].ls, t[t[o].ls].rs);
        swap(t[t[o].rs].ls, t[t[o].rs].rs);
        t[o].tag=0;
    }
}
void up(int o){ t[o].sz=t[t[o].ls].sz+t[t[o].rs].sz+1; }
void split(int o, int x, int &L, int &R){
    if(o==0) return L=R=0, void(); down(o);
    if(t[t[o].ls].sz+1>=x) R=o, split(t[o].ls, x, L, t[o].ls);
    else L=o, split(t[o].rs, x-t[t[o].ls].sz-1, t[o].rs, R);
    up(o);
}
int merge(int L, int R){
    if(L==0||R==0) return L+R;
    if(t[L].val>t[R].val) return down(L), t[L].rs=merge(t[L].rs, R), up(L), L;
    else return down(R), t[R].ls=merge(L, t[R].ls), up(R), R;
}