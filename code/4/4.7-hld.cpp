ll fa[N], dep[N], son[N], sz[N], top[N], idx[N], clk, ridx[N], out[N];
vector<int> g[N];
void predfs(int x, int f){ // 第一次 dfs 计算父亲/深度/大小/重儿子
    fa[x]=f, dep[x]=dep[f]+1, sz[x]=1;
    for(auto v:g[x]) if(v!=f){
        predfs(v, x);
        if(sz[v]>sz[son[x]]) son[x]=v;
        sz[x]+=sz[v];
    }
}

void dfs(int x, int tp){ // 第二次 dfs
    // top 链的顶端
    // idx 节点在 dfs 序中的编号
    // ridx dfs 序中编号对应的节点
    // out 以该节点为根的子树的编号的最大值
    // 即 dfs 序中 [idx, out] 表示以它为根的子树
    // [idx[top[x]], idx[x]] 表示这条链的顶端到该节点的一段链
    top[x]=tp, idx[x]=++clk, ridx[clk]=x;
    if(son[x]!=0) dfs(son[x], tp);
    for(auto v:g[x]) if(v!=fa[x]&&v!=son[x])
        top[v]=v, dfs(v, v);
    out[x]=clk;
}

void addpath(int u, int v, ll d){
    int uu=top[u], vv=top[v];
    while(uu!=vv){
        if(dep[uu]<dep[vv]) swap(u, v), swap(uu, vv);
        add(1, idx[uu], idx[u], d);
        u=fa[uu], uu=top[u];
    }
    if(dep[u]<dep[v]) swap(u, v);
    add(1, idx[v], idx[u], d);
}

void addtree(int x, ll d){
    add(1, idx[x], out[x], d);
}

ll sumpath(int u, int v){
    ll res=0;
    int uu=top[u], vv=top[v];
    while(uu!=vv){
        if(dep[uu]<dep[vv]) swap(u, v), swap(uu, vv);
        res=(res+sum(1, idx[uu], idx[u]))%P;
        u=fa[uu], uu=top[u];
    }
    if(dep[u]<dep[v]) swap(u, v);
    res=(res+sum(1, idx[v], idx[u]))%P;
    return res;
}

ll sumtree(int x){
    return sum(1, idx[x], out[x]);
}