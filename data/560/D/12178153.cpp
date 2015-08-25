//Language: GNU C++11


#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int maxn = 2e5+100;
char s1[maxn];
char s2[maxn];

bool dfs(char*a, char*b, int len)
{
    bool flag = true;
    for(int i = 0; i < len; i++){
        if(*(a+i) != *(b+i)){
            flag = false;
            break;
        }
    }
    if(flag) return true;
    if(len%2) return false;
    char *a1 = a + len/2;
    char *b1 = b + len/2;
    int len1 = len/2;
    if(dfs(a,b,len1) && dfs(a1, b1,len1)) return true;
    if(dfs(a1,b,len1) && dfs(a,b1,len1)) return true;
    return false;
}

int main()
{
    gets(s1);
    gets(s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2){
        cout << "NO" << endl;
        return 0;
    }
    bool flag = dfs(s1,s2, len1);
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
