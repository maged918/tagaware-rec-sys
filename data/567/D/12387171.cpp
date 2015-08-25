//Language: GNU C++


#include <bits/stdc++.h>
 
using namespace std;  
 
struct comp_int
{   bool operator()(const int& i1,const int& i2)
    {   return i1>i2;
    }
} ;
 
int main()
{   std::ios_base::sync_with_stdio(false);
    int n,k,a,m;
    cin>>n>>k>>a>>m;
    int curr=(n+1)/(a+1);
    set<int> placed;
    set<int,comp_int> placed2;
    placed.insert(0);
    placed.insert(n+1);
    placed2.insert(0);
    placed2.insert(n+1);
    int mov=m+1;
    for(int i=0;i<m;i++)
    {   int x;
        cin>>x;
        int ab=*placed.lower_bound(x);
        int lo=*placed2.lower_bound(x);
        curr=curr+((x-lo)/(a+1))+((ab-x)/(a+1))-((ab-lo)/(a+1));
        if(curr<k)mov=min(mov,i+1);
        //cout<<x<<" "<<lo<<" "<<ab<<" "<<curr<<endl;
        placed.insert(x);
        placed2.insert(x);
    }
    if(mov<=m)cout<<mov<<endl;
    else cout<<-1<<endl;
}
