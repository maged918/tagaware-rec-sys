//Language: GNU C++


#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <vector>
using namespace std;
int main(void)
{
        //freopen("in.txt", "r", stdin);
        //freopen("out1.txt", "w", stdout);
        //memset(dp1,0,5001*3001*sizeof(int));
        //map<long long int,   int>ma;
        //vector<long long int>::iterator iter;
        //memset(m,0,100000*sizeof(int));
        //for(int x=1;x<=n;x++)
        //scanf("%d%d",&a,&b);
        //printf("%d\n",0x7FFFFFFF);
        //freopen("ate.in ", "r", stdin);
        //freopen("ate.out ", "w", stdout);
        int a,s,d,f,g,h;
        scanf("%d%d%d%d%d%d",&a,&s,&d,&f,&g,&h);
        printf("%d\n",(a+s+d)*(a+s+d)-a*a-d*d-g*g);
        return 0;

}







