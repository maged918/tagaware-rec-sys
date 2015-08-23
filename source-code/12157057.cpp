//Language: GNU C++


/*I have given up the treatment-_-||*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=200010;
const int maxm=2000010;
const int INF=1e9;
const int mod1=1e9+7;
const int mod2=123456701;
int n,m;
struct Op
{
    int x;
    int t;
    LL l,r;
}pp[maxn];
struct Seg
{
    LL x;
    int type;
}ff[maxn];
bool cmp(Seg u,Seg v)
{
    if(u.x!=v.x)
        return u.x<v.x;
    return u.type<v.type;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=m;i++){
            scanf("%d%I64d%I64d%d",&pp[i].x,&pp[i].l,&pp[i].r,&pp[i].t);
        }
        LL ans=0;
        LL flagl=pow(2,(double)n-1);
        LL flagr=pow(2,(double)n)-1;
        int num=1;
        for(i=1;i<=m;i++){
            if(!pp[i].t) continue;
            int gg=n-pp[i].x;
            for(j=1;j<=gg;j++){
                pp[i].l<<=1;
            }
            for(j=1;j<=gg;j++){
                pp[i].r<<=1;
                pp[i].r|=1;
            }
            flagl=max(flagl,pp[i].l);
            flagr=min(flagr,pp[i].r);
        }
        if(flagr<flagl){
            printf("Game cheated!\n");
            continue;
        }
        num=1;
        for(i=1;i<=m;i++){
            if(pp[i].t) continue;
            int gg=n-pp[i].x;
            for(j=1;j<=gg;j++){
                pp[i].l<<=1;
            }
            for(j=1;j<=gg;j++){
                pp[i].r<<=1;
                pp[i].r|=1;
            }
            ff[num].x=pp[i].l;
            ff[num++].type=0;
            ff[num].x=pp[i].r;
            ff[num++].type=1;
        }
        sort(ff+1,ff+num,cmp);
        int gg=0;
        LL last=0;
        LL ll=flagl;
        for(i=1;i<num;i++){
            if(ff[i].type==0){
                gg++;
                if(gg==1) last=ff[i].x;
                if(gg==1&&ff[i].x-flagl>1){
                    if(ff[i].x>flagr+1&&flagr==flagl)
                        ans=flagl;
                    else{
                        ans=-1;
                        break;
                    }
                }
                else if(gg==1&&ff[i].x-flagl==1){
                    if(!ans||ans==flagl){
                        ans=flagl;
                    }
                    else{
                        ans=-1;
                        break;
                    }
                }
            }
            else{
                gg--;
                flagl=max(flagl,ff[i].x+1);
                if(ff[i].x>=flagr){
                    flagr=last-1;
                    break;
                }
            }
        }
        if(flagr>flagl||(flagr==flagl&&ans!=flagl&&ans>0)){
            ans=-1;
        }
        else if(flagr==flagl&&!ans){
            ans=flagl;
        }
        if(ans<0){
            printf("Data not sufficient!\n");
        }
        else if(!ans){
            printf("Game cheated!");
        }
        else{
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
