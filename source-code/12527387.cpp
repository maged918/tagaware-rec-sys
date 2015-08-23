//Language: GNU C++11


#include<bits/stdc++.h>
#include <stdio.h>
#include<set>
#include <unordered_map>
#include<map>
#include<queue>
#define sf(x) scanf("%d", &x);
#define scan(x) scanf("%I64d", &x);
#define pr(x) printf("%d ", x);
#define distance(x1,y1,x2,y2) sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> Vi;
/**********************************************
ll fact(ll x){ return (x==1 ?  1 : (x*fact(x-1))); }
/***************************************************
int gcd (int x,int y) {return ( y ? gcd(y,x%y) : x);}
/********************************************************/
void yala_bena(){cin.tie(0);std::ios::sync_with_stdio(0);}
/**********************************************************
void open(){ freopen("input.txt","r",stdin ); freopen( "output.txt","w",stdout );}
/********************************************************/
const int m_r=199999;
double pii=3.1415926536;
int match(char *s,  char *p, int overlap)
{
        int c = 0, l = strlen(p);

        while (*s != '\0') {
            if (strncmp(s++, p, l)) continue;
                if (!overlap) s += l - 1;
                c++;
        }
        return c;
}

int main()
{
yala_bena();
ll n,m;
cin>>n>>m;
if(n==1 && m==1)
    cout<<1<<endl;
else if(n-m > m-1)
    cout<<m+1<<endl;
else
    cout<<m-1<<endl;
}
