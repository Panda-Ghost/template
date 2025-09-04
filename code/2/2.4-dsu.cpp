ll n, fa[N];
void init(){
    iota(fa+1, fa+n+1, 1);
}

int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}

void merge(int x, int y){
    x=find(x), y=find(y);
    if(x!=y) fa[x]=y;
}