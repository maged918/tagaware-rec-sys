//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;
int n,ans;
typedef struct
{
    int a,x;
} Point;
Point t[109];

bool cmp(Point a,Point b)
{
    return a.x<b.x;
}
int main()
{
    scanf("%d",&n);
    int i,numf=0,numz=0;
    ans=0;
    for(i=0;i<n;i++)
        {
            scanf("%d%d",&t[i].x,&t[i].a);
            ans+=t[i].a;
            if(t[i].x<0) numf++;
            if(t[i].x>0) numz++;
        }
    sort(t,t+n,cmp);
   // cout<<ans<<endl;
    if(numf==numz||numf==numz+1||numz==numf+1) printf("%d",ans);
    else if(numf>numz)
    {

        for(i=0;i<numf-numz-1;i++)
            {
                ans-=t[i].a;
                //cout<<ans<<endl;
            }
        printf("%d",ans);
    }
    else
    {
        for(i=2*numf+1;i<numf+numz;i++)
            ans-=t[i].a;
        printf("%d",ans);
    }
    return 0;
}

			 	  		 	  		    	 		 		 		 	