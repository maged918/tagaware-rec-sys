//Language: GNU C++


#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int N;
    
   cin>>N;
    
    ll Numbers[N];
    int i=0;
    
    for(i=0;i<N;i++)
        cin>>Numbers[i];
    
    sort(Numbers,Numbers+N);
    
    int ans;
    if(Numbers[0]==1)
        ans=-1;
    else if(Numbers[0]!=1)
        ans=1;
    
    printf("%d\n",ans);
    return 0;       
}