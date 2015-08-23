//Language: GNU C++


#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
bool palin(int a){
    int n = 0;
    int aux = a;
    while(aux!=0){
        n = n*10 + (aux%10);
        aux/=10;
    }
    return n==a;
}
bool prime[10000010];
long long primes[10000010];
long long palins[10000010];
int N;
int p, q;
void sieve(){
    N = 10000000;
    int sq = (int)sqrt(N);
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i=2; i<=sq; i++){
        if(!prime[i]) continue;
        for(int j=i; j*i<=N; j++) prime[i*j] = false;
    }
    primes[0] = 0;
    for(int i=1; i<=N; i++) primes[i] = primes[i-1] + prime[i];
    for(int i=1; i<=N; i++) primes[i] = q*primes[i];
}
int palfill(){
    palins[0] = 0;
    for(int i=1; i<=N; i++){ 
        palins[i] = palins[i-1] + palin(i);
    }
    for(int i=1; i<=N; i++) palins[i] = p*palins[i];
}
int main(){

    int x;
    scanf("%d %d", &p, &q);
    sieve();
    palfill();
    int answer = 0;
    //printf("%d %d\n", primes[173], palins[173]);
    for(x=N; x>=1; x--){
        if(primes[x]<=palins[x]){
        //  printf("%d %d\n", primes[x], palins[x]);
        //  printf("%d %d\n", primes[x]/q, palins[x]/p);
            answer = x;
            break;
        }
    }
    //printf("%d %d\n", primes[41], palins[41]);
    if(answer==0 || answer == N) printf("Palindromic tree is better than splay tree\n");
    else printf("%d\n", answer);
    return 0;
}