// num 是该结点表示的前缀的回文后缀个数
// cnt 是该结点表示的回文串在原串中的出现次数（使用前需要向父亲更新）

namespace pam {
    int t[N][26], fa[N], len[N], rs[N], cnt[N], num[N];
    int sz, n, last;
    int _new(int l) {
        len[sz] = l; cnt[sz] = num[sz] = 0;
        return sz++;
    }
    // 记得 init
    void init() {
        memset(t, 0, sz * sizeof t[0]);
        rs[n = sz = 0] = -1;
        last = _new(0);
        fa[last] = _new(-1);
    }
    int get_fa(int x) {
        while (rs[n - 1 - len[x]] != rs[n]) x = fa[x];
        return x;
    }
    void ins(int ch) {
        rs[++n] = ch;
        int p = get_fa(last);
        if (!t[p][ch]) {
            int np = _new(len[p] + 2);
            num[np] = num[fa[np] = t[get_fa(fa[p])][ch]] + 1;
            t[p][ch] = np;
        }
        ++cnt[last = t[p][ch]];
    }
}