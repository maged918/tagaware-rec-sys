//Language: GNU C++11


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,i,m,x1,y1,x2,y2,cx,cy;
int main(){
    scanf("%d %d",&n,&m);
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    cx=max(x1,x2);
    cy=y1+y2;
    if(cx<=n&&cy<=m){
        cout<<"YES";
        return 0;
    }
    cx=x1+x2;
    cy=max(y1,y2);
    if(cx<=n&&cy<=m){
        cout<<"YES";
        return 0;
    }
//======================
    swap(x1,y1);
    cx=max(x1,x2);
    cy=y1+y2;
    if(cx<=n&&cy<=m){
        cout<<"YES";
        return 0;
    }
    cx=x1+x2;
    cy=max(y1,y2);
    if(cx<=n&&cy<=m){
        cout<<"YES";
        return 0;
    }
//======================
    swap(x1,y1);
    swap(x2,y2);
    cx=max(x1,x2);
    cy=y1+y2;
    if(cx<=n&&cy<=m){
        cout<<"YES";
        return 0;
    }
    cx=x1+x2;
    cy=max(y1,y2);
    if(cx<=n&&cy<=m){
        cout<<"YES";
        return 0;
    }
//====================
    swap(x1,y1);
    cx=max(x1,x2);
    cy=y1+y2;
    if(cx<=n&&cy<=m){
        cout<<"YES";
        return 0;
    }
    cx=x1+x2;
    cy=max(y1,y2);
    if(cx<=n&&cy<=m){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}