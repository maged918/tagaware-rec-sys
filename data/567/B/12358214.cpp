//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<string>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
using namespace std;
const int N = 2000005;
int first[N];
char op[N];
int a[N];
set< int > s;
int main()
{
    int n;
    memset(first,0,sizeof(first));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>op[i]>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(!first[a[i]])
        {
            if(op[i]=='+') first[a[i]] = 1;
            else first[a[i]] = 2;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(first[a[i]] == 2)
        {
            s.insert(a[i]);
        }
    }
    int mn = s.size();
    for(int i=0;i<n;i++)
    {
        if(op[i]=='+') s.insert(a[i]);
        else s.erase(a[i]);
        int sz = s.size();
        mn = max(sz,mn);
    }
    cout<<mn<<endl;
    return 0;
}
