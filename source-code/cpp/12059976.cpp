//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n];
    map<int,int>f,l,c;
    map<int,int>::iterator it;
    int maxx=0,m=0;
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        c[arr[i]]++;
        if (!f[arr[i]]) f[arr[i]]=i+1;
        l[arr[i]]=i+1;
    }
    vector<int>ans;
    for (it=c.begin();it!=c.end();it++)
    {
        if ((*it).second>=maxx) maxx=(*it).second;
    }
    for (it=c.begin();it!=c.end();it++)
    {
        if ((*it).second==maxx) ans.push_back((*it).first);
    }
    int ans1=0,ans2=0,minn=10e9;
    for (int i=0;i<ans.size();i++)
    {
        if (l[ans[i]]-f[ans[i]]<minn)
        {
            minn=l[ans[i]]-f[ans[i]];
            ans1=l[ans[i]]; ans2=f[ans[i]];
        }
    }
    cout<<ans2<<" "<<ans1<<endl;
    return 0;
}
