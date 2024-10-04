# template

## 数据结构

### zkw 线段树

单点修 区间查

```cpp
template<class T>
void build(int o, int l, int r, seg*s, const T& comp){
    for(M=1; M<=n+1; M<<=1);
    REP(i, 1, n) s[i+M].val=a[i];
    REPd(i, M-1, 1) s[i].val=f(s[2*i].val, s[2*i+1].val, comp);
}
template<class T>
ll qran(int o, int l, int r, seg* s, const T& comp, ll init){ ll res=init; for(l=l+M-1, r=r+M+1; l^r^1; l>>=1, r>>=1){ if(~l&1) res=f(res, s[l^1].val, comp); if(r&1) res=f(res, s[r^1].val, comp); } return res; }
template<class T>
void edit(int o, int x, ll v, seg* s, const T& comp){
    for(s[x+=M].val+=v, x>>=1; x; x>>=1){
        s[x].val=f(s[2*x].val, s[2*x+1].val, comp); }
    
}
```

### 珂朵莉树
```cpp


```