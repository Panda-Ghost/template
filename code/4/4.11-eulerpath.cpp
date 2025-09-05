ll n, m, cnt[N];
vector<int> g[N];
vector<int> path;
void dfs(int x){
    while(cnt[x]<g[x].size()){
        int u=g[x][cnt[x]];
        ++cnt[x];
        dfs(u);
    }
    path.push_back(x);
    // 最后要 reverse(path.begin(), path.end());
}