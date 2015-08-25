//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct interval{
     int x,y,sum;
};
bool cmp(interval c,interval d)
{
    return c.sum>d.sum ||( c.sum == d.sum && (c.y-c.x<d.y-d.x));
}
interval a[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        a[k].sum++;
//        printf("a[%d].sum = %d\n",k,a[k].sum);
        if(a[k].x==0)
        {
            a[k].x=i;
        }
        a[k].y=i;
    }
    sort(a,a+1000005,cmp);
    printf("%d %d\n",a[0].x,a[0].y);
    return 0;
}


				 	     	 			      	   					