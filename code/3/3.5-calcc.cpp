ll C[N][N];
void calcC(int n){
    C[0][0]=1;
    REP(i, 1, n){
        C[i][0]=C[i][i]=1;
        REP(j, 1, i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
}