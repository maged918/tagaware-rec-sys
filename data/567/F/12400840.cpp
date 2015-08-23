//Language: GNU C++


//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
vector<int>op[6][75];
ll dp[75][75];

int ckk(int l,int lf,int rt)
{
    int fl=0;
      for(int i=0;i<op[0][l].size();i++)
            if(op[0][l][i]!=l+1) return 0;
      for(int i=0;i<op[0][l+1].size();i++)
            if(op[0][l+1][i]!=l) return 0;
      for(int i=0;i<op[1][l].size();i++)
            if(op[1][l][i]>=lf&&op[1][l][i]<=rt) return 0;
      for(int i=0;i<op[1][l+1].size();i++)
            if(op[1][l+1][i]>=lf&&op[1][l+1][i]<=rt) return 0;
      for(int i=0;i<op[2][l].size();i++)
            if(op[2][l][i]==l+1) return 0;
      for(int i=0;i<op[2][l+1].size();i++)
            if(op[2][l+1][i]==l) return 0;
      for(int i=0;i<op[3][l].size();i++)
            if(op[3][l][i]>=lf&&op[3][l][i]<=rt&&op[3][l][i]!=l+1) return 0;
      for(int i=0;i<op[3][l+1].size();i++)
            if(op[3][l+1][i]>=lf&&op[3][l+1][i]<=rt&&op[3][l+1][i]!=l) return 0;
        return 1;
}
int ckkr(int l,int lf,int rt)
{
    int fl=0;
      for(int i=0;i<op[0][l].size();i++)
            if(op[0][l][i]!=l+1) return 0;
      for(int i=0;i<op[0][l+1].size();i++)
            if(op[0][l+1][i]!=l) return 0;
      for(int i=0;i<op[1][l].size();i++)
            if(op[1][l][i]>=lf&&op[1][l][i]<=rt) return 0;
      for(int i=0;i<op[1][l+1].size();i++)
            if(op[1][l+1][i]>=lf&&op[1][l+1][i]<=rt) return 0;
      for(int i=0;i<op[2][l].size();i++)
            if(op[2][l][i]==l+1) return 0;
      for(int i=0;i<op[2][l+1].size();i++)
            if(op[2][l+1][i]==l) return 0;
      for(int i=0;i<op[3][l].size();i++)
            if(op[3][l][i]>=lf&&op[3][l][i]<=rt&&op[3][l][i]!=l+1) return 0;
      for(int i=0;i<op[3][l+1].size();i++)
            if(op[3][l+1][i]>=lf&&op[3][l+1][i]<=rt&&op[3][l+1][i]!=l) return 0;
        return 1;
}

int ckklr(int l,int r)
{
     for(int i=0;i<op[0][l].size();i++)
            if(op[0][l][i]!=r) return 0;
      for(int i=0;i<op[0][r].size();i++)
            if(op[0][r][i]!=l) return 0;
     for(int i=0;i<op[1][l].size();i++)
        if(op[1][l][i]>=l&&op[1][l][i]<=r) return 0;
     for(int i=0;i<op[1][r].size();i++)
        if(op[1][r][i]>=l&&op[1][r][i]<=r) return 0;
     for(int i=0;i<op[3][l].size();i++)
        if(op[3][l][i]>=l&&op[3][l][i]<=r&&op[3][l][i]!=r) return 0;
     for(int i=0;i<op[3][r].size();i++)
        if(op[3][r][i]>=l&&op[3][r][i]<=r&&op[3][r][i]!=l) return 0;
    return 1;
}
vector<int>arr;
ll rec(int l,int r)
{
    if(r-l+1==2)
    {
        if(op[2][l].size()||op[2][r].size())
         return 0;
        for(int i=0;i<op[4][l].size();i++)
            if(op[4][l][i]!=r)return 0;
        for(int i=0;i<op[4][r].size();i++)
            if(op[4][r][i]!=l)return 0;
        for(int i=0;i<op[0][l].size();i++)
            if(op[0][l][i]!=r)return 0;
        for(int i=0;i<op[0][r].size();i++)
            if(op[0][r][i]!=l)return 0;
        return 1;
    }
    ll &ret=dp[l][r];
    if(ret!=-1)
      return ret;
    ret=0;
    //left-right
    int fl=ckklr(l,r);

      if(fl==1)
        ret=ret+rec(l+1,r-1);

    //Both left
     fl=ckk(l,l,r);
      if(fl==1)
        ret=ret+rec(l+2,r);
    //Both right
    fl=ckkr(r-1,l,r);
      if(fl==1)
        ret=ret+rec(l,r-2);
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d %d",&n,&k);
    char st[44];
    for(i=0;i<k;i++)
    {
        sn("%d %s %d",&a,&st,&b);
        a--;b--;
        if(a==b&&st[0]!='='&&strlen(st)==1)
        {
            pf("0\n");
            return 0;
        }
        if(a==b)continue;
        if(strcmp(st,"=")==0)
        {
            op[0][a].pb(b);
            op[0][b].pb(a);
        }
        if(strcmp(st,">")==0)
        {
            op[1][a].pb(b);
            op[2][b].pb(a);
        }
        if(strcmp(st,"<")==0)
        {
            op[2][a].pb(b);
            op[1][b].pb(a);
        }
        if(strcmp(st,">=")==0)
        {
            op[3][a].pb(b);
            op[4][b].pb(a);
        }
        if(strcmp(st,"<=")==0)
        {
            op[4][a].pb(b);
            op[3][b].pb(a);
        }


    }memset(dp,-1,sizeof(dp));
     pf("%I64d\n",rec(0,n+n-1));
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
