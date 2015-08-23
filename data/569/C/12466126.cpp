//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
#define MAX 2000000
int prime[MAX];
int pal[MAX];
void genPrime()
{
    memset(prime, -1, sizeof prime);
    prime[0]=prime[1] = 0;
    for(int i=4; i<MAX; i+=2)
        prime[i] = 0;
    int rt = sqrt(MAX);
    for(int i=3; i<=rt; i+=2){
        if(prime[i])
            for(int j=i*i; j<MAX; j+=i)
            prime[j] = 0;
    }
    for(int i=2; i<MAX; i++)
        prime[i] = prime[i-1]-prime[i];
}
void genPal()
{
    memset(pal, 0, sizeof pal);
    for(int i=1; i<MAX; i++)
    {
        int p = i;
        int q = 0;
        while(p){
            q =q*10+p%10;
            p/=10;
        }

        if(q==i)
            pal[i]= 1;
    }
    for(int i=1; i<MAX; i++)
        pal[i]+=pal[i-1];
}
int main()
{
    long long p, q;
    genPal();
    genPrime();
    cin>>p>>q;
    int mx = 1;
    for(int i=1; i<MAX; i++){
        if(q*prime[i]<=p*pal[i])
            mx = i;
    }
    cout<<mx<<endl;


}
