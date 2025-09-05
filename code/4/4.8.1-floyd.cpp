ll n, m, mincycle;
ll g[N][N], dis[N][N];
void floyd(){
    // 如果 g[i][j] 之间没边则存 inf
    // 注意 inf 的三倍不能爆 long long
    mincycle=LLONG_MAX/4;
    REP(i, 1, n) REP(j, 1, n) dis[i][j]=g[i][j];
    REP(k, 1, n){
        REP(i, 1, k-1)
            REP(j, i+1, k-1){
                mincycle=min(mincycle, dis[i][j]+g[j][k]+g[k][i]);
            }
        REP(i, 1, n)
            REP(j, 1, n)
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
    }
}