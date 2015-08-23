//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#define LL __int64
#define N 1200000
using namespace std;
bool prime[N + 20];
bool huiwen[N + 20];
int sump[N+20];
int sumh[N+20];
bool ok(int x)
{
    char s[20];
    sprintf(s,"%d", x);
    int len = strlen(s);
    for(int i = 0, j = len - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j]) return false;
    }
    return true;
}
void init()
{
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= N; i++)
    prime[i] = 1;
    for (int i = 2; i*i <= N; i++)
        if (prime[i])
            for (int j = i*i; j <= N; j += i)
                prime[j] = 0;
    for(int i = 2; i <= N; i++)
        sump[i] = sump[i - 1] + prime[i];
    for(int i = 1; i <= N; i++)
        sumh[i] += sumh[i - 1] + ok(i);
}
int main()
{
    init();
    int p,q;
    scanf("%d %d", &p, &q);
    double A = double(p)/q;
    int pos = -1;
    for (int i = 1; i < N; i++)
        if(sump[i] * q <= p*sumh[i])
            pos = i;
    if(pos == -1) printf("Palindromic tree is better than splay tree\n");
    else printf("%d\n", pos);
    return 0;
}
