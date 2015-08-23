//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <math.h>
#include <set>

using namespace std;

#define ft first
#define sc second
#define mp make_pair
#define pb push_back
#define forn(i, deb ,n) for(int i=deb;i<int(n);i++)

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;

const int borne =2*(int)1e6;
int compose[borne];
int pi[borne];
int rub[borne];
int is_pal(int n)
{
    vector<int>dec;
    for(;n;n/=10)
        dec.pb(n%10);
    int deb=0,fin=(int)dec.size()-1;
    while(deb<=fin)
    {
        if(dec[deb]!=dec[fin])
            return 0;
        deb++;
        fin--;
    }
    return 1;
}
int main()
{
    compose[1]=true;
    forn(i,2,borne)
    {
        if(compose[i])
            continue;
        for(int j=2;i*j<borne;j++)
            compose[i*j]=true;
    }
    forn(i,2,borne)
        pi[i]=pi[i-1]+(!compose[i]);
    rub[1]=1;
    forn(i,2,borne)
        rub[i]=rub[i-1]+is_pal(i);
    int p,q;
    cin>>p>>q;
    double A=(double)p/(double)q;
    for(int i=borne-1;i;i--)
        if(pi[i]<=A*rub[i])
        {
            cout<<i;
            return 0;
        }
    return 0;
}
