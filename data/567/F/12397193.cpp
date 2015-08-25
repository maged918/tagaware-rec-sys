//Language: GNU C++11


#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
typedef long long Int;
vector<int> Larger[101];
vector<int> LargerOrEqual[101];
vector<int> Equal[101];
int n,k;
Int F[101][101];
int vv[101];
bool chk(int k){
    int i;
    for (i=0;i<Equal[k].size();i++)if (vv[k]!=vv[ Equal[k][i] ])return false;
    for (i=0;i<LargerOrEqual[k].size();i++)if (vv[k]<vv[ LargerOrEqual[k][i] ])return false;
    for (i=0;i<Larger[k].size();i++)if (vv[k]<=vv[ Larger[k][i] ])return false;
    return true;
}
Int Solve(int L,int R,int val){
    if(val>n)return 0;
    if (F[L][R]!=-1)return F[L][R];
    if (R-L+1==2){
        vv[L]=vv[R]=val;
        if (chk(L) && chk(R))F[L][R]=1;else F[L][R]=0;
        vv[L]=vv[R]=999;
        return F[L][R];
    }
    Int ans=0;
    vv[L]=vv[L+1]=val;
    if ( chk(L) && chk(L+1) )ans+=Solve(L+2,R,val+1);
    vv[L]=999,vv[L+1]=999;
    vv[R]=vv[R-1]=val;
    if ( chk(R) && chk(R-1) )ans+=Solve(L,R-2,val+1);
    vv[R]=999,vv[R-1]=999;
    vv[L]=vv[R]=val;
    if ( chk(L) && chk(R) )ans+=Solve(L+1,R-1,val+1);
    vv[L]=999,vv[R]=999;
    return F[L][R]=ans;
}
int main(){
    int i,a,b;
    char op[4];
    memset(F,-1,sizeof(F));scanf("%d %d",&n,&k);
    for (i=1;i<=k;i++){
        scanf("%d%s%d",&a,op,&b);
        if (strlen(op)==1){
            if (op[0]=='=')Equal[a].push_back(b),Equal[b].push_back(a);
            else if (op[0]=='>')Larger[a].push_back(b); else Larger[b].push_back(a);
        }
        else{
            if (op[0]=='>')LargerOrEqual[a].push_back(b);else LargerOrEqual[b].push_back(a);
        }
    }
    for (i=1;i<=2*n;i++)vv[i]=999;
    printf("%I64d\n",Solve(1,2*n,1));
    return 0;
}
