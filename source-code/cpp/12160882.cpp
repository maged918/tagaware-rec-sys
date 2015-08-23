//Language: GNU C++


#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int map[105][2];
int di[105][2];
int gao[105][2];
int main()
{
    int n,i,low=0,upr=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&map[i][0],&map[i][1]);
        if(map[i][0]<0) {di[low][0]=map[i][0];di[low][1]=map[i][1];low++;}
        else {gao[upr][0]=map[i][0];gao[upr][1]=map[i][1];upr++;}
    }
    int flag=1,flagu=upr,flagl=low;
    long long int ans=0;
    if(low>upr) flag=0;
    while(!((low==0&&flag==0)||(upr==0&&flag==1)))
    {
        if(flag)
        {
            //printf("R\n");
            int min=1000006,x=0;
            for(i=0;i<flagu;i++)
            {
                if(min>gao[i][0]&&gao[i][0]!=10000006) {min=gao[i][0];x=i;}
            }
            ans+=gao[x][1];
            gao[x][0]=10000006;
            upr--;
        }
        else
        {
            //printf("L\n");
            int max=-10000010,x=0;
            for(i=0;i<flagl;i++)
            {
                if(max<di[i][0]&&di[i][0]!=-10000010) {max=di[i][0];x=i;}
            }
            ans+=di[x][1];
            //printf("L num,%d %d\n",x,max);
            di[x][0]=-10000010;
            low--;
        }
        //printf("ans=%I64d\n",ans);
        flag=1-flag;
    }
    printf("%I64d\n",ans);
    return 0;
}
//艹艹艹艹艹艹艹艹
 				   		  	  		 			 		   	  	