int n, m;
ll a[N], b[N], c[N];
ll inv2;

void solor(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if((j>>i)&1) continue;
            (a[j+(1<<i)]+=a[j])%=MOD;
            (b[j+(1<<i)]+=b[j])%=MOD;
        }
    }
    for(int j=0; j<m; ++j) c[j]=(a[j]*b[j])%MOD;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if((j>>i)&1) continue;
            a[j+(1<<i)]=(a[j+(1<<i)]-a[j]+MOD)%MOD;
            b[j+(1<<i)]=(b[j+(1<<i)]-b[j]+MOD)%MOD;
            c[j+(1<<i)]=(c[j+(1<<i)]-c[j]+MOD)%MOD;
        }
    }
    for(int j=0; j<m; ++j) prt(c[j]);
    puts("");
}

void soland(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if((j>>i)&1) continue;
            (a[j]+=a[j+(1<<i)])%=MOD;
            (b[j]+=b[j+(1<<i)])%=MOD;
        }
    }
    for(int j=0; j<m; ++j) c[j]=(a[j]*b[j])%MOD;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if((j>>i)&1) continue;
            a[j]=(a[j]-a[j+(1<<i)]+MOD)%MOD;
            b[j]=(b[j]-b[j+(1<<i)]+MOD)%MOD;
            c[j]=(c[j]-c[j+(1<<i)]+MOD)%MOD;
        }
    }
    for(int j=0; j<m; ++j) prt(c[j]);
    puts("");
}

void solxor(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if((j>>i)&1) continue;
            (a[j]+=a[j+(1<<i)])%=MOD;
            a[j+(1<<i)]=(a[j]-2*a[j+(1<<i)]+2*MOD)%MOD;
            (b[j]+=b[j+(1<<i)])%=MOD;
            b[j+(1<<i)]=(b[j]-2*b[j+(1<<i)]+2*MOD)%MOD;
        }
    }
    for(int j=0; j<m; ++j) c[j]=(a[j]*b[j])%MOD;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if((j>>i)&1) continue;
            a[j]=((a[j]+a[j+(1<<i)])*inv2)%MOD;
            a[j+(1<<i)]=(a[j]-a[j+(1<<i)]+MOD)%MOD;
            b[j]=((b[j]+b[j+(1<<i)])*inv2)%MOD;
            b[j+(1<<i)]=(b[j]-b[j+(1<<i)]+MOD)%MOD;
            c[j]=((c[j]+c[j+(1<<i)])*inv2)%MOD;
            c[j+(1<<i)]=(c[j]-c[j+(1<<i)]+MOD)%MOD;
        }
    }
    for(int j=0; j<m; ++j) prt(c[j]);
    puts("");
}