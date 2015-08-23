//Language: GNU C++


#include<iostream>
#include<map>
using namespace std;
main()
{
    map<long long , int>m;
   long long  n,b,d=0,bosh=0,ban=0;
   cin>>n;
    char a;
   for(int i=0; i<n; i++){
    cin>>a>>b;
   if(a=='+'){
          if(bosh)
          {
            bosh--;
          }
       else
            ban++;
           m[b]++;
   }
   else{
    if(!m[b])
       {
           ban++;
          bosh++;
       }
     else
       {
       m[b]--;
       bosh++;
           }
   }
  d=max(ban,d);
  }
   cout<<d;
}
