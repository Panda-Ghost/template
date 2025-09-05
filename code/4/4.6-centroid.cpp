ll n, sz[N], mxsz[N], G;
vector<int> g[N];
void dfs(int x, int fa){
    sz[x]=1, mxsz[x]=0;
    for(int u: g[x]) if(u!=fa){
        dfs(u, x);
        sz[x]+=sz[u];
        mxsz[x]=max(sz[u], mxsz[x]);
    }
    mxsz[x]=max(mxsz[x], n-sz[x]);
    if(G==-1||(mxsz[x]<mxsz[G]||(mxsz[x]==mxsz[G]&&x<G)))
        G=x;
}