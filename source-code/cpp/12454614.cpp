//Language: GNU C++


#include<cstdio>
#include<cstring>
#define MOD 1000000007
using namespace std;
#define LL long long
LL gfgf[4010][4010];
void init()
{
    gfgf[1][1]=1;
	for(int i=2;i<4010;i++)
	{
		gfgf[i][1] = gfgf[i - 1][i - 1];
		for(int j = 2; j <= i; j++)
            gfgf[i][j] = (gfgf[i][j-1] + gfgf[i - 1][j - 1]) % MOD;
	}
}
int main()
{
	int n;
	init();
	scanf("%d",&n);
    printf("%I64d\n", gfgf[n+1][n]);
	return 0;
}
/*
    while(scgfgfnf("%d%d%d",&t,&s,&p)!=EOF)
    {
        int gfgfns=1;
        t-=s*(p-1);
        while(1)
        {
            if(t<=s*(p-1)) bregfgfk;
            gfgfns++;
            t-=s*(p-1);
        }
        printf("%d\n",gfgfns);
    }
    return 0;
}
*/
