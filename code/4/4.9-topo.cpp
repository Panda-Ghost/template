ll n, in[N];
vector<int> g[N];
vector<int> res;
void topo(){
    // 不要忘记在建图时记录入度
    queue<int> q;
    REP(i, 1, n)
        if(in[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.front(); q.pop();
        res.push_back(u);
        for(int v: g[u]){
            --in[v];
            if(in[v]==0) q.push(v);
        }
    }
}
