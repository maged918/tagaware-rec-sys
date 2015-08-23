//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==1)
    {
        printf("%d\n",m);
        return 0;
    }
    int a;
    if(m<n/2)
        a=m+1;
    else if(m>n/2)
        a=m-1;
    else
        a=m+1;
    printf("%d\n",a);
    return 0;   
}