int nxt[N][150], cnt;
int num[N];
void insert(char *s, int len){
    // 字符串 s[0, len)
    // 0 为根结点
    int p=0;
    REP(i, 0, len-1){
        if(!nxt[p][s[i]]) nxt[p][s[i]]=++cnt;
        p=nxt[p][s[i]];
        ++num[p]; // 对前缀的统计在此处进行
    }
    // 对字符串整串的统计在此处进行
}

int find(char *s, int len){
    int p=0;
    REP(i, 0, len-1){
        if(!nxt[p][s[i]]) return 0;
        p=nxt[p][s[i]];
    }
    return num[p];
}