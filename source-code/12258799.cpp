//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<bitset>
#define M 300005
#define LL long long
#define uLL unsigned long long
#define oo 1000000007
using namespace std;
void Rd(int &res){
    char c; res=0;
    while(c=getchar(),!isdigit(c));
    do{
        res=(res<<3)+(res<<1)+(c^48);
    }while(c=getchar(),isdigit(c));
} 
struct node{
    LL L,R;
};
vector<node>T,F;
LL num[6*M]; 
int m=0;
int sum[6*M];
bool cmp(node A,node B){
    if(A.L!=B.L)return A.L<B.L;
    return A.R<B.R;
}
bool solveT(LL &L,LL &R){//交 
    L=T[0].L,R=T[0].R;
    for(int i=1;i<T.size();i++){
        if(T[i].L>R)return false;
        L=max(T[i].L,L);
        R=min(T[i].R,R);
    }
    return true;
}
void Add(LL x){
    num[m++]=x-1;num[m++]=x;num[m++]=x+1;
}
void update(LL L,LL R,int a){
    int x=lower_bound(num,num+m,L)-num;
    int y=lower_bound(num,num+m,R)-num;
    if(x>m||y>m)while(1);
    sum[x]+=a,sum[y+1]-=a;
}
LL solveF(LL L,LL R){//差  
    m=0;
    Add(L);Add(R);
    for(int i=0;i<F.size();i++){
        Add(F[i].L);Add(F[i].R);
    }
    sort(num,num+m);
    m=unique(num,num+m)-num;
    for(int i=0;i<=m;i++)sum[i]=0;
    update(L,R,1);
    for(int i=0;i<F.size();i++){
        update(F[i].L,F[i].R,-1);
    }
    if(m>6*M)while(1);
    for(int i=1;i<=m;i++){
        sum[i]+=sum[i-1];
    } 
    int cnt=0;LL ans;
    for(int i=0;i<m;i++){ 
        if(sum[i]>0){
            cnt++;ans=num[i];
        }
    } 
    if(cnt==0)return 0;
    else if(cnt>1)return -1;
    return ans;
}
int main(){
    int n,q,i,j,k;
    LL a,b;
    cin>>n>>q;
    LL Lid=1,Rid=1;
    for(i=1;i<n;i++){
        Lid<<=1;
        Rid<<=1;Rid|=1;
    }
    T.clear();F.clear();
    while(q--){ 
        cin>>i>>a>>b>>k; 
        while(i<n){
            a<<=1;
            b<<=1;b|=1;
            i++;
        }
        if(k==1)T.push_back((node){a,b});
        else F.push_back((node){a,b});
    }
    if(T.size()==0)T.push_back((node){Lid,Rid}); 
    sort(T.begin(),T.end(),cmp);
    if(!solveT(Lid,Rid))puts("Game cheated!");
    else{ 
        LL res=solveF(Lid,Rid); 
        if(res==0)puts("Game cheated!");
        else{
            if(res==-1)puts("Data not sufficient!");
            else cout<<res<<endl;
        }
    }
    return 0;
}