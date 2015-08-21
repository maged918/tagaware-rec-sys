//Language: GNU C++


#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i,j,num,maxnum,pos;
    int total[200];
    scanf("%d%d",&n,&m);
    for(i=0;i<=n;i++)
        total[i]=0;
    for(i=0;i<m;i++)
    {
        maxnum=0;
        pos=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&num);
            if(maxnum<num)
            {
                maxnum=num;
                pos=j;
            }
        }
        if(pos==0)
            pos=1;
        total[pos]++;
    }
    maxnum=0;
    pos=0;
    for(i=1;i<=n;i++)
    {
        if(maxnum<total[i])
        {
            maxnum=total[i];
            pos=i;
        }
    }
    printf("%d\n",pos);
    return 0;
}
