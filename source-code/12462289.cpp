//Language: GNU C++


#include<bits/stdc++.h>
using namespace std ;
#define INF (ll)1e7
typedef long long ll ;
ll primes[INF+5] ,palin[INF+5] ;
bool np[INF+5] ;

ll power(ll num,ll pw)
{
    if(pw == 1)
    return num;

    if(pw == 0)
    return 1 ;

    ll tmp = power(num,pw/2) ;

    tmp = tmp*tmp ;
    if(pw%2==0)
    return tmp ;
    else
    return tmp * num ;
}

bool check(ll x)
{
    ll tmp = x ;
    ll palin = 0 ;
    while(tmp)
    {
        palin *=10 ;
        palin += tmp%10 ;
        tmp/=10 ;
    }
 return (x==palin) ;
}


void sieve()
{
    np[0] = np[1] = true ;
    palin[0] = 0 ,palin[1] = 1 ;
    for(ll i = 2;i<=INF;i++)
    {
        if(!np[i])
        {
          for(ll j = i*i ;j<=INF;j+=i)
          {
             np[j] = true ;
          }
        primes[i] = primes[i-1] + 1 ;
        }else
        primes[i] = primes[i-1] ;

        palin[i] = palin[i-1] + check(i) ;
    }
    return ;
}


int main()
{
    ll p, q ;
    sieve() ;
    cin >> p >> q ;
    for(ll i = INF;i>0;i--)
    {
        if(q*primes[i]<=p*palin[i])
        {
        cout << i << endl ;
        return 0 ;
        }
    }
    cout << "Palindromic tree is better than splay tree" << endl ;
       return 0 ;
}
