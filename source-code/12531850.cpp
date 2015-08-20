//Language: GNU C++


#include<iostream>
#include<map>
#define ll long long int
using namespace std;
ll a[200005];
int main()
{
    int n,k,i;
    ll count=0;
    map<ll ,ll > m1,m2;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        m2[a[i]]++;
    }
    m2[a[0]]--;
    m1[a[0]]++;
    for(i=1;i<n;i++)
    {
        m2[a[i]]--;
        if(a[i]%k==0)
        {
            if(m1[a[i]/k] && m2[a[i]*k])
            {
                count+=m1[a[i]/k]*m2[a[i]*k];
            }
        }
        m1[a[i]]++;
    }
    cout<<count;
    return 0;
}