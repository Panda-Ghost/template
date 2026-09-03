// 洛谷模版题的代码为例

const int N = 2e6 + 100, M = 26;

int mp( char ch ) { return ch - 'a'; }

struct ACA {
  int ch[N][M], fail[N];
  int ridx[N], in[N];
  int sz;
  vector<int> topo; // 把拓扑序预处理出来 以便如果多次查询
  void init() {
    sz = 1;
    memset( ch[0], 0, sizeof ch[0] );
    in[0] = fail[0] = 0;
  }
  void insert( const string& s, int id ) {
    int n = s.size();
    int u = 0, c;
    for ( int i = 0; i < n; ++i ) {
      c = mp( s[i] );
      if ( !ch[u][c] ) {
        memset( ch[sz], 0, sizeof ch[sz] );
        in[sz] = fail[sz] = 0;
        ch[u][c] = sz++;
      }
      u = ch[u][c];
    }
    ridx[id] = u;
  }
  void build() {
    queue<int> Q;
    fail[0] = 0;
    for ( int c = 0, u; c < M; c++ ) {
      u = ch[0][c];
      if ( u ) {
        Q.push( u );
        fail[u] = 0;
        in[0]++;
      }
    }
    while ( !Q.empty() ) {
      int r = Q.front();
      Q.pop();
      for ( int c = 0, u; c < M; c++ ) {
        u = ch[r][c];
        if ( !u ) {
          ch[r][c] = ch[fail[r]][c];
          continue;
        }
        fail[u] = ch[fail[r]][c];
        in[fail[u]]++;
        Q.push( u );
      }
    }
  }
  void calc_topo() {
    queue<int> Q;
    for ( int i = 0; i < sz; ++i )
      if ( in[i] == 0 )
        Q.push( i );
    while ( !Q.empty() ) {
      int u = Q.front();
      Q.pop();
      topo.push_back( u );
      if ( !u ) continue;
      in[fail[u]]--;
      if ( in[fail[u]] == 0 )
        Q.push( fail[u] );
    }
  }
} ac;

int n;
char s[N];
int cnt[N];

int main() {
  n = rd();
  ac.init();
  for ( int i = 1; i <= n; ++i ) {
    scanf( "%s", s );
    ac.insert( s, i );
  }
  ac.build();
  ac.calc_topo();
  scanf( "%s", s );
  int u = 0, len = strlen( s );
  for ( int i = 0; i < len; ++i ) {
    u = ac.ch[u][mp( s[i] )];
    ++cnt[u];
  }
  for ( int i : ac.topo )
    cnt[ac.fail[i]] += cnt[i];
  for ( int i = 1; i <= n; ++i )
    printf( "%d\n", cnt[ac.ridx[i]] );
  return 0;
}
