//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int A[100001];
int F[100001],No[100001],vis[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,i,m=INT_MIN;

    cin>>N;

    for(i=0;i<N;++i)
        {
            cin>>A[i];
            m=max(A[i],m);
        }

    pair < int, int > temp;
    queue <   pair < int  , int >   > q;
    for(i=0;i<N;++i)
    {
        q.push(make_pair(A[i],0));
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(vis[temp.first]==i+1 || temp.first>m)
                continue;
            vis[temp.first]=i+1;
            ++F[temp.first];
            No[temp.first]+=temp.second;
            q.push(make_pair(temp.first*2,temp.second+1));
            q.push(make_pair(temp.first/2,temp.second+1));
        }
    }
    int ans=INT_MAX;
    for(i=0;i<=100000;++i)
        if(F[i]==N)
                {
                    ans=min(ans,No[i]);
                }

    cout<<ans;
    return 0;
}
