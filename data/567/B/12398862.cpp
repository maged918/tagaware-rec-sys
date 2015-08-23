//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int visit[1000005];
int main()
{
    int n,a;
    scanf("%d",&n);
    int maxn=0;
    int old=0;
    int ans=0;
    char ch;
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=n;i++)
    {
        scanf(" %c %d",&ch,&a);
        if(ch=='-')
        {
            if(visit[a]==1||visit[a]==2)
            {
                ans--;
                visit[a]=0;
            }
            else if(visit[a]==0)
            {
                visit[a]=-1;
                old=maxn+1;
                maxn=old;
            }
        }
        if(ch=='+')
        {
            if(visit[a]==0)
            {
                visit[a]=1;
                ans++;
                if(ans>maxn)
                    maxn=ans;
            }
            else if(visit[a]==-1)
            {
                ans++;
                visit[a]=2;
                if(ans>maxn)
                    maxn=ans;
            }
        }
    }
    printf("%d\n",max(old,maxn));

    return 0;
}
/*
6
- 2
- 3
+ 2
+ 3
- 2
- 3

*/

  			    						 	  	  	   				