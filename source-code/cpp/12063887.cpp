//Language: GNU C++11


#include<bits/stdc++.h>
#define LL long long
#define pii pair<LL,int>
#define F first
#define S second
using namespace std;

vector<pii> p ;
main()
{
    int h,Q ; scanf("%d%d",&h,&Q) ;
    LL ma=(1LL<<h)-1 ;
    for(int q=1;q<=Q;q++)
    {
        int h0,ans ; LL L,R ; scanf("%d%I64d%I64d%d",&h0,&L,&R,&ans) ;
        L=max((LL)L,1LL<<(h0-1)) ; R=min((LL)R,(1LL<<h0)-1) ;
        if(ans && R<L){printf("Game cheated!\n") ; return 0 ;}
        else if(R<L) continue ;

        LL L2=L*(1LL<<(h-h0)) , R2=(R+1)*(1LL<<(h-h0))-1 ;
        if(ans)
            p.push_back(pii(L2,1)) ,
            p.push_back(pii(R2+1,-1)) ;
        else
        {
            p.push_back(pii(1LL<<(h-1),1)) ;
            p.push_back(pii(L2,-1)) ;
            p.push_back(pii(R2+1,1)) ;
            p.push_back(pii(ma+1,-1)) ;
        }
    }
    p.push_back(pii(ma/2+1,1)) ;
    p.push_back(pii(ma+1,-1)) ;
    Q++ ;
    sort(p.begin(),p.end()) ;
    LL tmp=-1,ans=-1 ;
    bool mul=0 ;
    for(int i=0,now=0;i<p.size();)
    {
        int j=i ;
        while(j<p.size() && p[i].F==p[j].F)
            now+=p[j++].S ;
        if(now==Q)
        {
            if(ans!=-1) mul=1 ;
            else if(tmp==-1) tmp=p[i].F ;
        }
        else if(ans==-1 && tmp!=-1)
        {
            ans=tmp ;
            if(p[i].F==tmp+1) tmp=-1 ;
            else mul=1 ;
        }
        i=j ;
    }
    if(ans==-1) printf("Game cheated!\n") ;
    else if(mul) printf("Data not sufficient!\n") ;
    else printf("%I64d\n",ans) ;
}
