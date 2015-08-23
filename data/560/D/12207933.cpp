//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#define ll __int64
#define INF 0x3fffffff
using namespace std;

char s1[200005];
char s2[200005];

bool dfs(int l1,int r1,int l2,int r2)
{
    if((r1-l1)&1){
        bool flag=true;
        int i=l1,j=l2;
        while(i<r1){
            if(s1[i]!=s2[j]){
                flag=false;
                break;
            }
            i++;
            j++;
        }
        if(flag) return true;
        else return false;
    }
    else{
        return (dfs(l1,(r1+l1)/2,l2,(r2+l2)/2)&&dfs((r1+l1)/2,r1,(r2+l2)/2,r2))||(dfs(l1,(r1+l1)/2,(r2+l2)/2,r2)&&dfs((r1+l1)/2,r1,l2,(r2+l2)/2));
    }
}

int main()
{
    //freopen("d:\\Test.txt","r",stdin);
    scanf("%s",s1);
    scanf("%s",s2);
    int len=strlen(s1);
    if(dfs(0,len,0,len)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
