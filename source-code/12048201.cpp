//Language: GNU C++


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include<climits>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,x,n) for(int i=x;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define OI(X) printf("%d",X);
#define RS(X) scanf("%s", (X))
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define Dpoint  strcut node{int x,y}
#define cmpd int cmp(const int &a,const int &b){return a>b;}

 /*#ifdef HOME
    freopen("in.txt","r",stdin);
    #endif*/
const int MOD = 1e9+7;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
//#define HOME

int Scan()
{
	int res = 0, ch, flag = 0;

	if((ch = getchar()) == '-')				//�ж���
		flag = 1;

	else if(ch >= '0' && ch <= '9')			//�õ��������
		res = ch - '0';
	while((ch = getchar()) >= '0' && ch <= '9' )
		res = res * 10 + ch - '0';

	return flag ? -res : res;
}
/*----------------PLEASE-----DO-----NOT-----HACK-----ME--------------------*/


int a[100000+5];
int b[1000000+5];
int l[1000000+5];
int r[1000000+5];
int main()
{
int n;
RI(n);
MS0(b);
MS1(l);
MS1(r);
REP(i,0,n)
{RI(a[i]);
b[a[i]]++;
if(l[a[i]]==-1)
    l[a[i]]=i+1;
r[a[i]]=i+1;
}
int ansl=-1,ansr=-1;
int MAX=0;
int L=INT_MAX;
REP(i,1,1000000+1)
{if(b[i]>MAX)
{
    MAX=b[i];
    ansl=l[i];
    ansr=r[i];
    L=r[i]-l[i]+1;
}
else
    if(b[i]==MAX)
    {
        if(r[i]-l[i]+1<L)
        {
            ansl=l[i];
            ansr=r[i];
            L=r[i]-l[i]+1;
        }

    }

}
printf("%d %d\n",ansl,ansr);


        return 0;
}

