//Language: GNU C++


#include"iostream"
#include"cstring"
#include"cstdio"
#include"algorithm"

using namespace std;

int num[100005];

int getabs(int x)
{
    if(x < 0) return -x;
    return x;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&num[i]);
    sort(num,num+n);
    for(int i = 0;i < n;i++)
    {
        if(i == 0)
        {
            printf("%d %d\n",getabs(num[0]- num[1]),getabs(num[0] - num[n-1]));
        }
        else if(i == n-1)
        {
            printf("%d %d\n",getabs(num[i] - num[i-1]),getabs(num[i] - num[0]));
        }
        else
        {
            int minn = min(getabs(num[i]-num[i-1]),getabs(num[i]-num[i+1]));
            int maxx = max(getabs(num[i]-num[0]),getabs(num[i]-num[n-1]));
            printf("%d %d\n",minn,maxx);
        }
    }
    return 0;
}
