//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;

#define pb push_back
#define mp make_pair

map<lol,lol> before,after;

int main()
{
    lol n,k;
    cin>>n>>k;
    lol a[n];
    lol ans=0;
    for(lol i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(lol i=n-1;i>=0;i--)
    {
        map<lol,lol>::iterator it;
        it=after.find(a[i]);
        if(it==after.end()) after.insert(mp(a[i],1));
        else it->second++;
    }
    for(lol i=0;i<n;i++)
    {
        map<lol,lol>::iterator it;
        it=after.find(a[i]);
        if(it->second==1) after.erase(a[i]);
        else it->second--;
        if(!(a[i]%k))
        {
            map<lol,lol>::iterator A,B;
            A=before.find(a[i]/k);
            B=after.find(a[i]*k);
            if(A!=before.end() && B!=after.end())
            {
                ans+=(A->second * B->second);
            }
        }
        it=before.find(a[i]);
        if(it!=before.end()) it->second++;
        else before.insert(mp(a[i],1));
    }
    cout<<ans;
    return 0;
}
