int RL[N];
// 最后结果的 RL 的说明：
// 加了字符 '#' 的字符串中 [i - RL[i], i + RL[i]] 是极大回文串
// 在原串中 RL[i] 正好是以 (i-1)/2 为中心极大回文串长度（不论奇偶）
void manacher( char* a, int n ) { // "abc" => "#a#b#c#"
  int r = 0, p = 0;
  REP( i, 0, n - 1 ) {
    if ( i < r )
      RL[i] = min( RL[2 * p - i], r - i );
      // 上面这行 r-i 还是 r-i+1 结果一样，尊重原作者
    else
      RL[i] = 1;
    while ( i - RL[i] >= 0 && i + RL[i] < n && a[i - RL[i]] == a[i + RL[i]] )
      RL[i]++;
    if ( RL[i] + i - 1 > r ) {
      r = RL[i] + i - 1;
      p = i;
    }
  }
  REP( i, 0, n - 1 ) --RL[i];
}