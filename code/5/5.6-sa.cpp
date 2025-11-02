int buf1[N], buf2[N], buc[N];

// str 存储在下标 [1, n] 的范围内，str[0] 要与 str[1..n] 都不相同
// ht[i] = LCP(sa[i], sa[i-1])
void sufsort(char str[], int n, int sa[], int rk[], int ht[]){
    int *x=buf1, *y=buf2, m=127;
    REP(i, 0, m) buc[i]=0;
    REP(i, 1, n) buc[x[i]=str[i]]++;
    REP(i, 1, m) buc[i]+=buc[i-1];
    REPd(i, n, 1) sa[buc[x[i]]--]=i;
    for(int k=1; k<=n; k<<=1){
        int p=0;
        REP(i, n-k+1, n) y[++p]=i;
        REP(i, 1, n) if(sa[i]>k) y[++p]=sa[i]-k;
        REP(i, 0, m) buc[i]=0;
        REP(i, 1, n) buc[x[y[i]]]++;
        REP(i, 1, m) buc[i]+=buc[i-1];
        REPd(i, n, 1) sa[buc[x[y[i]]]--]=y[i];
        swap(x, y), x[sa[1]]=p=1;
        REP(i, 2, n)
            if(y[sa[i-1]]==y[sa[i]]&&\
                y[sa[i-1]+k]==y[sa[i]+k]) x[sa[i]]=p;
            else x[sa[i]]=++p;
        if((m=p)>=n) break;
    }
    REP(i, 1, n) rk[sa[i]]=i;
    for(int j=0, k=0, i=1; i<=n; ht[rk[i++]]=k)
        for(k?k--:0, j=sa[rk[i]-1];\
            str[i+k]==str[j+k]; k++);
}