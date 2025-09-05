ll n, m, fa[N], weight_sum;
pair<ll, pair<int, int>> edge[M];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void kruskal(){
    weight_sum=0;
    sort(edge+1, edge+m+1);
    iota(fa+1, fa+n+1, 1);
    REP(i, 1, m){
        auto [u, v]=edge[i].second;
        u=find(u), v=find(v);
        if(u==v) continue;
        fa[u]=v;
        weight_sum+=edge[i].first;
    }
}