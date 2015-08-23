//Language: MS C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#include<set>
template <class T>
bool scanff(T &ret){
    char c; int sgn; T bit=0.1;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    if(c==' '||c=='\n'){ ret*=sgn; return 1; }
    while(c=getchar(),c>='0'&&c<='9') ret+=(c-'0')*bit,bit/=10;
    ret*=sgn;
    return 1;
}//正负数
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define drep(i,a,b) for(int i=a;i>=b;i--)
#define mset(s,v) memset(s,v,sizeof(s))
#define mcp(a,b) memcpy(a,b,sizeof(b))
#define gep(x) for(int i=start[x];~i;i=nw[i].nxt)
#define inf 1e9+9
#define MM 400100
#define NN 30010
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int n,a[101010],vis[101010];
int pd[101010],pos[101010];
int main(){
    scanf("%d",&n);
    int tot=0;
    rep(i,1,n){
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }

    rep(i,1,n) if(!vis[i]) pd[++tot]=i;
    int js=1;
    rep(i,1,n){
        if(vis[a[i]]>1){
            while(vis[a[i]]>1){
                vis[a[i]]--;
                a[i]=pd[js++];
                vis[a[i]]++;
            }
        }
    }
    tot=0;
    rep(i,1,n) {
        if(!vis[i]) pd[++tot]=i;
        if(a[i]<=n) pos[i]=1;
    }
    js=1;
    rep(i,1,n){
        if(vis[i]==0){
            rep(j,1,n){
                if(!pos[j]){
                    vis[i]++;
                    a[j]=i;
                    pos[j]=1;
                    break;
                }

            }
        }
    }
        printf("%d",a[1]);
        rep(i,2,n) printf(" %d",a[i]);
        printf("\n");
        return 0;


}
