//Language: GNU C++


#include <iostream>
using namespace std;

const int N = 100000;
const int INF = 100000000;


int a[N+1];
int level[N+1];
int L[N+1], R[N+1], ON[N+1];
int ans[N+1];
int n;



void build()
{
    level[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        level[i] = level[i/2]+1;
    }
}

void init()
{
    int num;
    
    
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        
        num = a[i];
        
        ans[1] += level[num]-level[1];
        ON[num]++;
        
        while(num != 1)
        {
            if(num%2 == 0)
            {
                L[num/2]++;
            }
            else
            {
                R[num/2]++;
            }
            num /= 2;
        }
    }
}

void solve()
{
    int now, next;
    int UP = 0;
    int Min = INF;
    
    for(now = 1; ; now = next)
    {
        Min = min(Min, ans[now]);
        
        if(L[now] == 0 && ON[now] == 0 && UP == 0)
        {
            next = now*2+1;
            if(next > N) break;
            ans[next] = ans[now] - R[now];
        }
        else
        {
            UP += ON[now] + R[now];
            next = now*2;
            if(next > N) break;
            ans[next] = ans[now] + UP - L[now];
        }
        
    }
    
    cout << Min << endl;
    
}

int main()
{
    build();
    init();
    solve();
}
