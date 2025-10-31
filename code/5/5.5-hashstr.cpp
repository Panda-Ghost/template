#define ENABLE_DOUBLE_HASH

namespace hashstr{

typedef unsigned long long ull;
const int x=135;
const int p1=0x3b3b3bbb, p2=1e9+1011;
ull xp1[N], xp2[N];

// 记得 init
void init_xp(){
    xp1[0]=xp2[0]=1;
    for(int i=1; i<N; ++i){
        xp1[i]=xp1[i-1]*x%p1;
        xp2[i]=xp2[i-1]*x%p2;
    }
}

struct str{
    char s[N];
    int length;
    ull h[N];

    ull hash(){
        length=strlen(s);
        ull res1=0, res2=0;
        h[length]=0;
        for(int j=length-1; j>=0; --j){
        #ifdef ENABLE_DOUBLE_HASH
            res1=(res1*x+s[j])%p1;
            res2=(res2*x+s[j])%p2;
            h[j]=(res1<<32)|res2;
        #else
            res1=(res1*x+s[j])%p1;
            h[j]=res1;
        #endif
        }
        return h[0];
    }
    // 左闭右开区间
    ull get_substr_hash(int left, int right) const {
        int len=right-left;
    #ifdef ENABLE_DOUBLE_HASH
        unsigned int mask32=~(0u);
        ull left1=h[left]>>32, right1=h[right]>>32;
        ull left2=h[left]&mask32, right2=h[right]&mask32;
        return (((left1-right1*xp1[len]%p1+p1)%p1)<<32)|
               (((left2-right2*xp2[len]%p2+p2)%p2));
    #else
        return ((h[left]-h[right]*xp1[len]%p1+p1)%p1);
    #endif
    }
};

}