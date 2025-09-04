bitset<N> b;
ll n, phi[N];
vector<ll> prime;
void euler(){
    REP(i, 2, n){
        if(!b[i]){
            prime.push_back(i);
            phi[i]=i-1;
        }
        for(int p: prime){
            if(p*i>n) break;
            b[p*i]=1;
            if(i%p==0){
                phi[p*i]=phi[i]*p;
                break;
            }
            phi[p*i]=phi[i]*phi[p];
        }
    }
}

