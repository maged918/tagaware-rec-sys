//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
     int a1,b1,a2,b2,a3,b3,f=0;
     cin>>a1>>b1;
     cin>>a2>>b2;
     cin>>a3>>b3;
     if((a2+a3<=a1&&b2<=b1&&b3<=b1)||(a2+b3<=a1&&a3<=b1&&b2<=b1))
     f=1;
     else if((a2+a3<=b1&&b2<=a1&&b3<=a1)||(a2+b3<=b1&&a3<=a1&&b2<=a1))
     f=1;
     else if((b2+b3<=b1&&a2<=a1&&a3<=a1)||(a3+b2<=b1&&a2<=a1&&b3<=a1))
     f=1;
     else if((b2+b3<=a1&&a2<=b1&&a3<=b1)||(a3+b2<=a1&&a2<=b1&&b3<=b1))
     f=1;
     if(f==0)
     cout<<"NO";
     else
     cout<<"YES";
     return 0;
}