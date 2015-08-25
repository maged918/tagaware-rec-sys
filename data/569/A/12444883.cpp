//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main(void)
 {
    int t,s,q;
    scanf("%d %d %d",&t,&s,&q);
    int i,ans=s,count=0;
    while(ans<t)
    {
    for(i=1;i<=ans;i++)
    {
        s=s+q-1;
        if(s>=t)
        break;
    }
    count++;
    ans=s;
    }
    printf("%d",count);

    return 0;
}
