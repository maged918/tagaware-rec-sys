//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<set>
#include<vector>
#define make(k,n,t) for(int i = 0; i < n; ++i) t[i]=k;
using namespace std;
typedef long long ll;
const double eps= 1e-8;
const int INF = 2147483647;
const int maxn = 300010;
char str[maxn];
int main()
{
    int n, m;
    while(cin >> n >> m){
        scanf(" %s", str+1);
        int cur=0;
        for(int i = 2; i < n+1; ++i)
            if(str[i]=='.' && str[i-1]=='.')
                cur++;
        int ans = cur;
        for(int t = 1; t <= m; ++t){
            cur = ans;
            int i;
            char q;
            scanf("%d %c", &i, &q);
            if(q=='.'){
                if(str[i]=='.'){
                    ans = cur;
                }
                else{
                    if(str[i-1] == '.'&& str[i+1] != '.'){
                        ans=cur+1;
                    }else if(str[i-1] == '.' && str[i+1] == '.'){
                        ans=cur+2;
                    }else if(str[i-1] != '.' && str[i+1] != '.'){
                        ans=cur;
                    }else if(str[i-1] != '.' && str[i+1] == '.'){
                        ans=cur+1;
                    }
                }
            }else{
                if(str[i]=='.'){
                    if(str[i-1]=='.'&&str[i+1]!='.'){
                        ans=cur-1;
                    }else if(str[i-1]=='.' && str[i+1]=='.'){
                        ans=cur-2;
                    }else if(str[i-1]!='.'&&str[i+1]!='.'){
                        ans=cur;
                    }else if(str[i-1]!='.'&&str[i+1]=='.'){
                        ans=cur-1;
                    }
                }else{
                    ans = cur;
                }
            }
            str[i]=q;
            cout << ans << endl;
        }
    }
    return 0;
}
