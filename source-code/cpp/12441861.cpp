//Language: GNU C++


#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int N = 100010;
int a[N],c[N],b[N];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
    }
    for(i=1;i<=n;i++) {
        if(c[i]==0) v.push_back(i);
    }
    for(i=0;i<n;i++) {
        if(a[i]<=n && b[a[i]]==0) {
            cout<<a[i]<<' ';
            b[a[i]]=1;
            c[a[i]]--;
        }
        else {
            x=v.back();
            cout<<x<<' ';
            v.pop_back();
            b[x]=1;
            c[a[i]]--;
        }
    }
    return 0;
}