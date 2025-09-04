bitset<N> b;
ll n;
vector<ll> prime;
void erato(){
    REP(i, 2, n) if(!b[i]){
        prime.push_back(i);
        for(int j=i+i; j<=n; j+=i)
            b[j]=1;
    }
}
