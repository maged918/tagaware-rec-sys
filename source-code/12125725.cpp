//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    int h,q;
    cin>>h>>q;
    long long a=1,b=1,c=1;
    while(c!=h)
    {
        a*=2;
        b=b*2+1;
        c++;
    }
    vector<pair<long long,long long> > v;
    for(int f=0;f<q;f++)
    {
        long long i,l,r,x;
        cin>>i>>l>>r>>x;
        while(i!=h)
        {
            i++;
            l*=2;
            r=r*2+1;
        }
        if(x==0)
        {
            v.push_back(make_pair(l,r));
        }
        else
        {
            if(r!=b)
                v.push_back(make_pair(r+1,b));
            if(l!=a)
                v.push_back(make_pair(a,l-1));
        }
    }
    if(h==1&&v.size()==0)
    {
        cout<<1<<endl;
        return 0;
    }
    if(v.size()==0)
    {
        cout<<"Data not sufficient!\n";
        return 0;
    }
    sort(v.begin(),v.end());
    long long ans=v[0].first-a,ans1=0,maxi=v[0].second;
    if(v[0].first>a)
        ans1=a;
    if(b>v[v.size()-1].second)
        ans1=b;
    for(int f=1;f<v.size();f++)
    {
        if(v[f].first-maxi-1>0){
            ans1=v[f].first-1;
            ans+=v[f].first-maxi-1;
        }
        maxi=max(maxi,v[f].second);
    }
    ans+=b-maxi;
    if(ans>1)
        cout<<"Data not sufficient!\n";
    else if(ans==0)
        cout<<"Game cheated!\n";
    else
        cout<<ans1<<"\n";
}
