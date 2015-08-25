//Language: GNU C++11


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int n,a,x,pos=0,neg=0,ans=0;
   cin>>n;
   vector <pair<int,int> > left, right;
   for(int i=0; i<n; i++)
   {
        cin>>x>>a;
        if(x<0)
        {
            left.push_back(make_pair(-x,a));
            neg++;
        }
        else
        {
            right.push_back(make_pair(x,a));
            pos++;
        }

   }
   sort(left.begin(),left.end());
   sort(right.begin(),right.end());
   if(pos>neg)
   {
        for(int i=0; i<neg; i++)
        {
            ans=ans+left[i].second+right[i].second;
        }
        ans=ans+right[neg].second;
   }
   else if(neg>pos)
   {
        for(int i=0; i<pos; i++)
        {
            ans=ans+left[i].second+right[i].second;
        }
        ans=ans+left[pos].second;
   }
   else
   {
        for(int i=0; i<pos; i++)
        {
            ans=ans+left[i].second+right[i].second;
        }
   }
   cout<<ans;
}
