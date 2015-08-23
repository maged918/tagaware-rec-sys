//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("d.txt","r",stdin);
    int h,q;
    while(~scanf("%d%d",&h,&q)) {
        vector<pair<long long,long long> >V,U;
        long long L=1LL<<(h-1);
        long long R=(1LL<<h)-1;
        for(int i=0;i<q;i++) {
            long long level,l,r,tf;
            scanf("%I64d%I64d%I64d%I64d",&level,&l,&r,&tf);
            for(int j=level+1;j<=h;j++) {
                l=l<<1;
                r=r<<1|1;
            }
            if(tf==1) {
                if(l-1>=L) {
                    V.push_back(make_pair(L,l-1));
                }
                if(r+1<=R) {
                    V.push_back(make_pair(r+1,R));
                }
            }
            else {
                V.push_back(make_pair(l,r));
            }
        }
        sort(V.begin(),V.end());
        for(int i=0;i<V.size();i++) {
            if(i==0) {
                U.push_back(V[0]);
            }
            else if(U.back().second+1>=V[i].first) {
                U.back().second=max(U.back().second,V[i].second);
            }
            else {
                U.push_back(V[i]);
            }
        }
        if(U.size()==0&&L==R) {
            printf("1\n");
            continue;
        }
        if(U.size()==1&&U[0].first==L+1&&U[0].second==R) {
            printf("%I64d\n",L);
            continue;
        }
        if(U.size()==1&&U[0].first==L&&U[0].second==R-1) {
            printf("%I64d\n",R);
            continue;
        }
        if(U.size()==1&&U[0].first==L&&U[0].second==R) {
            printf("Game cheated!\n");
            continue;
        }
        if(U.size()==2&&U[0].first==L&&U[1].second==R&&U[1].first==U[0].second+2) {
            printf("%I64d\n",U[0].second+1);
            continue;
        }
        printf("Data not sufficient!\n");
    }
    return 0;
}
