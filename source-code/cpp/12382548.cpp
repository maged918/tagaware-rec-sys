//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
const int INF=1000000;
vector<int> a;
void f(int x)
{
    if(x==0)
        return;
    f(x-1);
    swap(a[x],a[x-1]);
}
int main()

{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   long long n;
   cin >> n;
   long long a[n];
   for(int i=0;i<n;i++)
    cin >> a[i];
   for(int i=0;i<n;i++)
   {
       if(i>0)
       {
           if(i<n-1)
           {
               cout << min(abs(a[i+1]-a[i]),abs(a[i]-a[i-1]))<<" ";
               cout << max(abs(a[n-1]-a[i]),abs(a[i]-a[0]))<<"\n";
           }
           if(i==n-1)
           {
               cout << abs(a[i]-a[i-1])<<" ";
               cout << abs(a[i]-a[0])<<"\n";
           }


       }
       else
       {
           cout << abs(a[1]-a[0])<< " "<< abs(a[n-1]-a[0])<<"\n";

       }
   }



}
