//Language: GNU C++11


#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include <fstream>
using namespace std;

int main()
{
    long long t, a, b;
    while(scanf("%I64d%I64d%I64d", &t, &a, &b)!=EOF)
    {
        long long ans = 1;
        while(1)
        {
            a = a * b;
            if(a < t) {ans++; continue;}
            if(a>=t) break;
        }
        printf("%I64d\n",ans);
    }
}