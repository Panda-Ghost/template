// s[0, n)
// d1[i] 表示 [i-d1[i], i+d1[i]] 是奇数长度回文 (i 为中心)
// d2[i] 表示 [i-d2[i]+1, i+d2[i]] 是偶数长度回文 (i+0.5 为中心)
// d2[i] 为 0 表示不存在

int l=0, r=-1;
for(int i=0; i<n; ++i){
    if(r<i){
        int j=i;
        while(j>0&&2*i-(j-1)<n&&s[j-1]==s[2*i-(j-1)])
            --j;
        d1[i]=i-j;
        l=j, r=2*i-j;
    }else{
        int j=(l+r)-i;
        if(j-d1[j]<=l){
            int k=i*2-r;
            while(k>0&&2*i-(k-1)<n&&s[k-1]==s[2*i-(k-1)])
                --k;
            d1[i]=i-k;
            l=k, r=2*i-k;
        }else d1[i]=d1[j];
    }
}

l=0, r=-1;
for(int i=0; i+1<n; ++i){
    if(r<i){
        int j=i;
        while(j>=0&&i+i+1-j<n&&s[j]==s[i+i+1-j]) --j;
        d2[i]=i-j;
        l=j+1, r=i+i+1-j-1;
    }else{
        int j=(l+r)-i-1;
        if(j<0||j-d2[j]<l){
            int k=i+i+1-r-1;
            while(k>=0&&i+i+1-k<n&&s[k]==s[i+i+1-k])
                --k;
            d2[i]=i-k;
            l=k+1, r=i+i+1-k-1;
        }else d2[i]=d2[j];
    }
}