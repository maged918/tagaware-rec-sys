//Language: GNU C++


#include<bits/stdc++.h>
#include<stdint.h>
#include<stdio.h>
#include<sstream>
using namespace std;
int64_t a[200005];
int main(){
 
  map<int64_t,map<int64_t,int64_t> > dp;
  int n,k;
  int64_t ans = 0;
  scanf("%d%d",&n,&k);
  
  for(int i=0;i<n;i++){
      scanf("%lld",&a[i]);
  }
  
  for(int i=n-1;i>=0;i--){
      
     
      if(dp[a[i]*k][2] > 0){
          dp[a[i]][3] += dp[a[i]*k][2];
      }
      if(dp[a[i]*k][1] > 0){
          dp[a[i]][2] += dp[a[i]*k][1];
      }
      
      dp[a[i]][1]++;
      
  }
  
  for(int i=0;i<n;i++){
        // cout<<a[i]<<" = "<<dp[a[i]][1]<<" "<<dp[a[i]][2]<<" "<<dp[a[i]][3]<<"\n";
         ans += dp[a[i]][3];
         dp[a[i]][3] = 0;
      
  }
  cout<<ans;
  
  
  
}