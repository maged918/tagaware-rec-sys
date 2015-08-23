//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

#define l long long
#define mod 1000000007
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

/*
    replace endl with

*/
int max_(int ar[],int n)
{
    int z=INT_MIN,index;
    for(int i=0;i<n;i++)
    {
        if(z<ar[i])
        {
            z=ar[i];index=i;
        }
    }
    return index;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    int ar[m][n];
    //m-no of cities
    //n-no of candidates
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)cin>>ar[i][j];
    }

    int h[n];memset(h,0,sizeof(h));
    for(int i=0;i<m;i++)
    {
        int u=max_(ar[i],n);

        h[u]++;
    }

    cout<<max_(h,n)+1;
}
