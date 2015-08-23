//Language: MS C++


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <iostream>
//#include <math.h>
#include <queue>
#include <map>
using  namespace std;
const int N = 20;
typedef long long LL;
#define eps 1e-9
queue<int>q;
map<int ,int >vis;
int main ()
{
    double n,a[100010],t,s,q;
    while(scanf("%lf %lf %lf",&t,&s,&q)!=EOF)
    {
        int i;
        for(i=1;;i++)
        {
            double x;
            //x=s+x*(q-1)/q;
            x=s*q;
            s=x;
            if(s>=t)
                break;
        }
        printf("%d\n",i);
    }
    return 0;
}