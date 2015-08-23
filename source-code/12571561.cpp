//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include  <map>
#include <limits>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int n,m,v,h,a;
char s[500008];
vector <int> gr[500008][28];
vector<int> arr[500008];
int intime[500008],outtime[500008],tim=0;
void dfs(int node,int depth){
    tim++;
    gr[depth][s[node-1]-'a'].push_back(tim);
    intime[node]=tim;
    for(int i=0;i<arr[node].size();i++){
        dfs(arr[node][i],depth+1);
    }
    outtime[node]=tim;
}
int main(int argc, char const *argv[])
{
    scan(n);
    scan(m);
    for(int i=2;i<=n;i++){
        scan(a);
        arr[a].push_back(i);
    }
    scanf("%s",s);
    dfs(1,1);
    while(m--){
        scan(v);
        scan(h);
        int odd=0;
        int count=0;
        for(int i=0;i<26;i++){
            count=upper_bound(gr[h][i].begin(),gr[h][i].end(),outtime[v])-lower_bound(gr[h][i].begin(),gr[h][i].end(),intime[v]);
            if(count%2==1){
                odd++;
                if(odd>1){
                break;
                }
            }
            
        }
        if(odd>1){
            puts("No");
        }
        else{
            puts("Yes");
        }
    }
    return 0;
}