char s1[N];
int n, pi[N];
void solve(){
    // 字符串存于 s1[0, n)
    pi[0]=0;
    REP(i, 1, n-1){
        int j=pi[i-1];
        while(j>0&&s1[j]!=s1[i]) j=pi[j-1];
        if(s1[j]==s1[i]) ++j;
        pi[i]=j;
    }
}