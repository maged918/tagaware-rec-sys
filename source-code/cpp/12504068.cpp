//Language: GNU C++11


#include<iostream>
#include<fstream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

#define NMAX 300005

int St[4*NMAX],Dr[4*NMAX],sol[4*NMAX];
char c[NMAX];

void update(int nod, int st, int dr, int poz, int val)
{
    int mij;
    if(st==dr) {
        St[nod]=val;
        Dr[nod]=val;
        sol[nod]=0;
        return ;
    }
    mij=(st+dr)/2;
    if(poz<=mij)
        update(nod*2,st,mij,poz,val);
    else update(nod*2+1,mij+1,dr,poz,val);
    if(St[2*nod]==mij-st+1)
        St[nod]=St[2*nod]+St[2*nod+1];
    else St[nod]=St[2*nod];
    if(Dr[2*nod+1]==dr-mij)
        Dr[nod]=Dr[2*nod+1]+Dr[2*nod];
    else Dr[nod]=Dr[2*nod+1];
    if(St[2*nod]==mij-st+1 && Dr[2*nod+1]==dr-mij)
        sol[nod]=0;
    else if(St[2*nod]==mij-st+1)
        sol[nod]=sol[2*nod+1];
    else if(Dr[2*nod+1]==dr-mij)
        sol[nod]=sol[2*nod];
    else sol[nod]=sol[2*nod]+Dr[2*nod]+St[2*nod+1]-(St[2*nod+1]+Dr[2*nod]!=0)+sol[2*nod+1];
}

int main ()
{
    std::ios::sync_with_stdio(false);
    int n,i,p,m;
    char ch;
    //ifstream cin("code.in");
    cin>>n>>m;
    cin>>(c+1);
    for(i=1;i<=n;i++)
        if(c[i]=='.')
            update(1,1,n,i,1);
        else update(1,1,n,i,0);
    for(i=1;i<=m;i++) {
        cin>>p>>ch;
        if(ch=='.')
            update(1,1,n,p,1);
        else update(1,1,n,p,0);
        if(St[1]==n)
            cout<<n-1;
        else cout<<St[1]-(St[1]!=0)+sol[1]+Dr[1]-(Dr[1]!=0);
        cout<<'\n';
    }
    return 0;
}