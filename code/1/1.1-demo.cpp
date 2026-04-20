#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP( i, a, b ) for ( int i = ( a ); i <= ( b ); ++i )
#define REPd( i, a, b ) for ( int i = ( a ); i >= ( b ); --i )
inline ll rd() { /* {{{ */
  ll r = 0, k = 1;
  char c;
  while ( !isdigit( c = getchar() ) )
    if ( c == '-' )
      k = -k;
  while ( isdigit( c ) )
    r = r * 10 + c - '0', c = getchar();
  return r * k;
}
inline void prt( ll x ) {
  printf( "%lld ", x );
} /* }}} */

int main() {

  return 0;
}