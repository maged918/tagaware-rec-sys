//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1,b1,a2,b2,a,b;
    while(cin>>a>>b>>a1>>b1>>a2>>b2)
    {
        int flag=0;
        int l1=a1+a2;
        if(l1<=a)
        {
            if(b1<=b && b2<=b) flag=1;
        }
        int l2=a1+b2;
        if(l2<=a)
        {
            if(b1<=b && a2<=b) flag=1;
        }
         l1=b1+b2;
        if(l1<=a)
        {
            if(a1<=b && a2<=b) flag=1;
        }
         l2=b1+a2;
        if(l2<=a)
        {
            if(a1<=b && b2<=b) flag=1;
        }
        l1=a1+a2;
        if(l1<=b)
        {
            if(b1<=a && b2<=a) flag=1;
        }
        l2=a1+b2;
        if(l2<=b)
        {
            if(b1<=a && a2<=a) flag=1;
        }
         l1=b1+b2;
        if(l1<=b)
        {
            if(a1<=a && a2<=a) flag=1;
        }
         l2=b1+a2;
        if(l2<=b)
        {
            if(a1<=a && b2<=a) flag=1;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");


    }
    return 0;
}
