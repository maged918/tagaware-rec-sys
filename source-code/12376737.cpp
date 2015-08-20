//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;

#define pb psuh_back
#define mp make_pair


int n,k,a,m;
set<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>a>>m;
    s.insert(0);
    s.insert(n+1);
    int curr=(n+1)/(a+1);
    bool flag=false;
    int b[m+3];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0;i<m;i++)
    {
        set<int>::iterator A,B;
        B=s.lower_bound(b[i]);
        A=s.lower_bound(b[i]);
        A--;
        int low=*A;
        int high=*B;
        curr=curr-(high-low)/(a+1);
        curr=curr+(b[i]-low)/(a+1) + (high-b[i])/(a+1);
        if(curr<k)
        {
            cout<<i+1;
            flag=true;
            break;
        }
        s.insert(b[i]);
    }
    if(!flag) cout<<"-1";
    return 0;
}