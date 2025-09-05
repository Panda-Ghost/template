ll n, m, dis[N], vis[N];
vector<pair<int, ll>> g[N];
void dijkstra(int s){
    fill_n(dis+1, n, LLONG_MAX/2);
    fill_n(vis+1, n, 0);
    dis[s]=0;
    priority_queue<pair<ll, int>> q;
    q.push(make_pair(0, s));
    while(!q.empty()){
        int u=q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v, w]: g[u]){
            if(vis[v]) continue;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push(make_pair(-dis[v], v));
            }
        }
    }
}