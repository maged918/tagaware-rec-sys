//Language: GNU C++


// O(n) Solution

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
#define llu long long unsigned int
#define lli long long int
#define li long int
#define pii pair<int,int>
#define fi first
#define se second   
#define pb push_back
#define mod 1000000007
#define vi vector<int>
#define mp make_pair

/*int scan()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
li scanli()    {int ip=getchar_unlocked(),flag=1;li ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lli scanlli()    {int ip=getchar_unlocked(),flag=1;lli ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scanllu()    {int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
void print(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void printli(li n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printlli(lli n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void printllu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
*/
int mini=1000000000;
vi a(1000010),cntbelow(1000010,0),costbelow(1000010,0);
void func(int node,int cost_so_far,int nodes_outside_subtree)
{
    mini=min(mini,cost_so_far+costbelow[node]);
    if(node>50000)
        return;
    int current=cntbelow[node]-cntbelow[2*node]-cntbelow[2*node+1];
    func(2*node,cost_so_far+nodes_outside_subtree+current+costbelow[2*node+1]+2*cntbelow[2*node+1],nodes_outside_subtree+current+cntbelow[2*node+1]);
    if(nodes_outside_subtree+current+cntbelow[2*node]==0)
        func(2*node+1,cost_so_far+nodes_outside_subtree+current+costbelow[2*node]+2*cntbelow[2*node],nodes_outside_subtree+current+cntbelow[2*node]);
}   
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,i,j,k;
    cin>>n; 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        cntbelow[a[i]]++;
    }
    for(i=100000;i>=1;i--)
    {
        cntbelow[i]+=(cntbelow[2*i]+cntbelow[2*i+1]);
        costbelow[i]=costbelow[2*i+1]+costbelow[2*i]+cntbelow[2*i]+cntbelow[2*i+1];
    }
    func(1,0,0);
    cout<<mini<<endl;
    return 0;
}