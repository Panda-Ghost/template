# template

## 写在前面



## 数据结构

### zkw 线段树

单点修 区间查

```cpp

ll s[N<<2];
int M;

ll f(ll x, ll y){
    return x+y;
}

void build(){
    for(M=1; M<=n+1; M<<=1);
    REP(i, 1, n) s[i+M]=a[i];
    REPd(i, M-1, 1) s[i]=f(s[2*i], s[2*i+1]);
}

ll qrange(int l, int r, ll init){
    ll res=init;
    for(l=l+M-1, r=r+M+1; l^r^1; l>>=1, r>>=1){
        if(~l&1) res=f(res, s[l^1]);
        if(r&1) res=f(res, s[r^1]); 
    }
    return res;
}

void edit(int x, ll v){
    for(s[x+=M]=v, x>>=1; x; x>>=1){
        s[x]=f(s[2*x], s[2*x+1].val);
    }
}

ll qpoint(int x){
    return s[x+M];
}
```

### 珂朵莉树
```cpp


```