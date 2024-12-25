constexpr ll INF = LLONG_MAX / 2;

struct E {
    int from, to; ll cp, v;
    E() {}
    E(int f, int t, ll cp, ll v) : from(f), to(t), cp(cp), v(v) {}
};

struct MCMF {
    static const int M = 1E5 * 5;
    int n, m, s, t;
    vector<E> edges;
    vector<int> G[M];
    bool inq[M];
    ll d[M], a[M];
    int p[M];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        REP (i, 0, n + 1) G[i].clear();
        edges.clear(); m = 0;
    }

    void addedge(int from, int to, ll cap, ll cost) {
        edges.emplace_back(from, to, cap, cost);
        edges.emplace_back(to, from, 0, -cost);
        G[from].push_back(m++);
        G[to].push_back(m++);
    }

    bool BellmanFord(ll &flow, ll &cost) {
        REP (i, 0, n + 1) d[i] = INF;
        memset(inq, 0, sizeof inq);
        d[s] = 0, a[s] = INF, inq[s] = true;
        queue<int> Q; Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = false;
            for (int& idx: G[u]) {
                E &e = edges[idx];
                if (e.cp && d[e.to] > d[u] + e.v) {
                    d[e.to] = d[u] + e.v;
                    p[e.to] = idx;
                    a[e.to] = min(a[u], e.cp);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = true;
                    }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += a[t] * d[t];
        int u = t;
        while (u != s) {
            edges[p[u]].cp -= a[t];
            edges[p[u] ^ 1].cp += a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    pair<ll, ll> go() {
        ll flow = 0, cost = 0;
        while (BellmanFord(flow, cost));
        return make_pair(flow, cost);
    }
} MM;