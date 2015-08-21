//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
#include<ctype.h>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#define read() freopen("input.txt","r",stdin)
#define write() freopen("output.txt","w",stdout)
#define mem(a, b) memset(a, b, sizeof(a))
#define mx 100005
#define lli long long
#define psi pair<string,int>
#define uu first
#define vv second
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        char ch, pch;
        string id;
        int tmp=0, p=0;
        map <string, int> check;
        int cnt[105], a=0;
        for(int i=0; i<n; i++){
            cin>>ch>>id;
            if(ch=='+'){
                check[id]=1;
                if(i and pch=='-'){
                    cnt[a++]=tmp;
                    tmp=p;
                }
                tmp++; p++;
            }
            else{
                if(check[id]==1){
                    p--;
                }
                else{
                    tmp++;
                    for(int i=0; i<a; i++) cnt[i]++;
                }
                //check[id]=0;
            }
            pch=ch;
        }
        cnt[a++]=tmp;
        int c=0; for(int i=0; i<a; i++) if(c<cnt[i]) c=cnt[i];
        cout<<c<<endl;
    }
    return 0;
}
