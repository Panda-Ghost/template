ll n, m, dis[N], inq[N], cnt[N];
vector<pair<int, ll>> g[N];
bool spfa(int s){
    // 如果有负环则 return true
    queue<int> q;
    fill_n(dis+1, n, LLONG_MAX/2);
    fill_n(inq+1, n, 0);
    fill_n(cnt+1, n, 0);
    dis[s]=0, inq[s]=cnt[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        inq[u]=0;
        for(auto [v, w]: g[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>n) return true;
                if(!inq[v]){
                    inq[v]=1, q.push(v);
                }
            }
        }
    }
    return false;
}