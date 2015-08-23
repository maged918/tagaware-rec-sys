//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <vector>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define LL long long

vector <pair<LL,int> > G;
vector <pair<LL,LL> > N;

int main(){
    int H,Q;
    LL L,R;
    scanf("%d%d",&H,&Q);
    L=1;
    for(int i=0;i<H-1;i++){
        L*=2;
    }
    R=L*2-1;
    LL al=L,ar=R;
    for(int i=0;i<Q;i++){
        int lv,k;
        LL l,r;
        scanf("%d%lld%lld%d",&lv,&l,&r,&k);\
        r++;
        for(int i=0;i<H-lv;i++){
            l*=2; r*=2;
        }
        r--;
        if(k){
            al=max(al,l);
            ar=min(ar,r);
        }
        else {
            G.pb(mp(l,-1)); G.pb(mp(r,1));
        }
    }
    G.pb(mp(L-1,0));G.pb(mp(R+1,0));
    if(al>ar) { printf("Game cheated!\n"); return 0; }
    sort(G.begin(),G.end());
    int tot=0;
    for(int i=0;i<G.size()-1;i++){
        tot+=G[i].second;
        if(tot==0){
            N.pb(mp(G[i].first+1,G[i+1].first-1));
        }
    }
    LL num=0;
    LL res=-1;
    for(int i=0;i<N.size();i++){
        LL cl=N[i].first,cr=N[i].second;
        if(cl>cr) continue;
        cl=max(cl,al);
        cr=min(cr,ar);
        if(cr>=cl){
            num+=(cr-cl+1);
            res=cr;
        }
    }
    if(num>1){
        printf("Data not sufficient!\n");
    }
    else if(num==0){
        printf("Game cheated!\n");
    }
    else printf("%lld\n",res);
    return 0;
}
