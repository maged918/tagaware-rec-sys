//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
const int N=1600010;
char S[N],T[N];
bool dfs(int ss,int se,int ts,int te){
    int flag=1;
    if(ss==se)return S[ss]==T[ts];
    for(int i=0;i<=se-ss;i++){
        if(S[i+ss]!=T[ts+i])
            flag=0;
    }
    if(flag)return true;
    if((se-ss+1)%2)return false;
    int mid=(se-ss)/2;
    if(dfs(ss,ss+mid,ts,ts+mid)&&
       dfs(ss+mid+1,se,ts+mid+1,te))
        return true;
    if(dfs(ss,ss+mid,ts+mid+1,te)&&
       dfs(ss+mid+1,se,ts,ts+mid))
        return true;
    return false;
}
int main(){
    scanf("%s%s",S,T);
    int len=strlen(S);
    puts(dfs(0,len-1,0,len-1)?"YES":"NO");
    return 0;
}
