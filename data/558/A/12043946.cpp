//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int cmp(pair<int,int>a,pair<int,int>b)
{
    return abs(a.first)<abs(b.first);
}
int main()
{
    //freopen("a.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)) {
        vector<pair<int,int> >V1,V2;
        for(int i=0;i<n;i++) {
            int p,v;
            scanf("%d%d",&p,&v);
            if(p<0) {
                V1.push_back(make_pair(p,v));
            }
            else {
                V2.push_back(make_pair(p,v));
            }
        }
        sort(V1.begin(),V1.end(),cmp);
        sort(V2.begin(),V2.end(),cmp);
        int x=min(V1.size(),V2.size());
        int ans=0;
        for(int i=0;i<x;i++) {
            ans+=V1[i].second;
            ans+=V2[i].second;
        }
        if(V1.size()>x) {
            ans+=V1[x].second;
        }
        else if(V2.size()>x) {
            ans+=V2[x].second;
        }
        printf("%d\n",ans);
    }
    return 0;
}
