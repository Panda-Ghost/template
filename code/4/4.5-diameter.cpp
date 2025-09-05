ll n, dep[N], mxdep[N];
vector<int> g[N];
vector<int> dmt;
void dfs1(int x, int fa){
    dep[x]=dep[fa]+1;
    mxdep[x]=1;
    for(int u: g[x]) if(u!=fa){
        dfs1(u, x);
        mxdep[x]=max(mxdep[u]+1, mxdep[x]);
    }
}

void dfs2(int x, int fa){ // 找一条直径，如果只需要直径长度则不用
    dmt.push_back(x);
    int nxt=-1;
    for(int u: g[x]) if(u!=fa){
        if(nxt==-1||mxdep[u]>mxdep[nxt]) nxt=u;
    }
    if(nxt!=-1)
        dfs2(nxt, x);
}

void diameter(){
    dep[0]=0;
    dfs1(1, 0);
    int rt=max_element(dep+1, dep+n+1)-dep;
    dfs1(rt, 0);
    dfs2(rt, 0);
}