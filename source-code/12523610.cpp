//Language: GNU C++


#pragma comment(linker, "/STACK:102400000,102400000")
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#define LL __int64
#define eps 1e-8
#define in64(a) scanf("%I64d",&a)
#define out64(a) printf("%I64d",a)
#define zero(x) ((x > +eps) - (x < -eps))
#define mem(a,b) memset(a,b,sizeof(a))
#define MOD 1000000007
#define INF 99999999
#define MAX 500010
using namespace std;

struct NODE
{
    int cou[26];
};

int n, m;
int dep[MAX], first[MAX], last[MAX], cnt, high;
bool ans[MAX];
char str[MAX];
vector<int> v[MAX], height[MAX];
vector<struct NODE> num[MAX];

void dfs(int u, int depth)
{
    high = max(high, depth);
    dep[u] = depth;
    height[depth].push_back(u);
    int size = v[u].size();
    first[u] = cnt ++;
    for(int i = 0; i < size; i ++)
    {
        int x = v[u][i];
        dfs(x, depth + 1);
    }
    last[u] = cnt;
}

int cmp(int x, int y)
{
    return first[x] < first[y];
}

int main()
{
    int u, d, re;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 2; i <= n; i ++)
        {
            scanf("%d",&re);
            v[re].push_back(i);
        }
        cnt = 1;
        dfs(1,1);
        scanf("%s",str);
        for(int i = 1; i <= high; i ++)
        {
            sort(height[i].begin(),height[i].end(),cmp);
            int size = height[i].size();
            struct NODE temp;
            mem(temp.cou,0);
            num[i].push_back(temp);
            for(int j = 0; j < size; j ++)
            {
                int x = height[i][j] - 1;
                temp.cou[str[x] - 'a'] ++;
                num[i].push_back(temp);
                height[i][j] = first[x+1];
            }
        }
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%d",&u,&d);
            if(dep[u] >= d)
            {
                printf("Yes\n");
            }
            else if(d > high)
            {
                printf("Yes\n");
            }
            else
            {
                int st = lower_bound(height[d].begin(), height[d].end(), first[u]) - height[d].begin();
                int ed = lower_bound(height[d].begin(), height[d].end(), last[u]) - height[d].begin();
                if(st <= ed)
                {
                    int c = 0;
                    for(int j = 0; j < 26; j ++)
                    {
                        if((num[d][ed].cou[j] - num[d][st].cou[j])&1)
                        {
                            c ++;
                        }
                    }
                    if(c < 2)
                    {
                        printf("Yes\n");
                    }
                    else
                    {
                        printf("No\n");
                    }
                }
                else
                {
                    printf("Yes\n");
                }
            }
        }
    }
    return 0;
}