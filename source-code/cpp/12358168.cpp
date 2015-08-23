//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> ii;
int n;
long long x[1000002];
vector<long long> v;
vector<pair<long long,long long> > b;
long long min1,max1,minn,maxn;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        v.push_back(x[i]);
    }
    sort(x,x+n);
    min1=abs(x[0]-x[1]);
    max1=abs(x[n-1]-x[0]);
    minn=abs(x[n-1]-x[n-2]);
    maxn=abs(x[n-1]-x[0]);
    //b.push_back(ii(min1,max1));
    //b.push_back(ii(minn,maxn));
    for(int i=1;i<n-1;i++)
    {
        b.push_back(ii(min(abs(x[i]-x[i-1]),abs(x[i]-x[i+1])),max(abs(x[i]-x[n-1]),abs(x[i]-x[0]))));
    }
    cout<<min1<<" "<<max1<<endl;
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i].first<<" "<<b[i].second<<endl;
    }
    cout<<minn<<" "<<maxn<<endl;
}
