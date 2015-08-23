//Language: GNU C++11


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#define dbg(x) cerr<<#x<<" is : "<<x<<'\n';
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n;i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    vector<pair<int, int> > ans(n);
    ans[a[0].second].first = a[1].first - a[0].first;
    ans[a[0].second].second = a[n-1].first - a[0].first;
    ans[a[n-1].second].first = a[n-1].first - a[n-2].first;
    ans[a[n-1].second].second = a[n-1].first - a[0].first;
    for(int i = 1; i < n-1;i++)
    {
        ans[a[i].second].first = min(a[i].first-a[i-1].first,a[i+1].first-a[i].first);
        ans[a[i].second].second = max(a[i].first-a[0].first,a[n-1].first-a[i].first);
    }
    for(int i = 0; i < n;i++)
    {
        cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    }
}
