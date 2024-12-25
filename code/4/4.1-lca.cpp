void dfs(int x, int fa){
    pa[x][0]=fa; dep[x]=dep[fa]+1;
    REP(i, 1, SP) pa[x][i]=pa[pa[x][i-1]][i-1];
    for(int& v:g[x]) if(v!=fa){
        dfs(v, x);
    }
}

int lca(int x, int y){
    if (dep[x]<dep[y]) swap(x, y);
    int t=dep[x]-dep[y];
    REP(i, 0, SP) if(t&(1<<i)) x=pa[x][i];
    REPd(i, SP-1, -1){
        int xx=pa[x][i], yy=pa[y][i];
        if (xx!=yy) x=xx, y=yy;
    }
    return x==y?x:pa[x][0];
}