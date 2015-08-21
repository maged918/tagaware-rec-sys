//Language: GNU C++11


#include<cstdio>
#include<algorithm>
using namespace std;
int v[7];
int main(){
    //freopen("std.in","r",stdin);
    //freopen("std.out","w",stdout);
    for(int i=1;i<=6;i++)
        scanf("%d",&v[i]);
    int add=2*v[1]+1;
    long long res=0;
    for(int i=1;i<=min(v[2],v[6]);i++){
        res=res+add;
        add+=2;
    }
    add--;
    for(int i=min(v[2],v[6])+1;i<=v[2]+v[3]-min(v[5],v[3]);i++)
        res+=add;
    add--;
    for(int i=v[2]+v[3]-min(v[5],v[3])+1;i<=v[2]+v[3];i++){
        res+=add;
        add-=2;
    }
    printf("%I64d",res);
    return 0;
}
