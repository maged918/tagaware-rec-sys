//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=100010;
int main()
{
    int A[6];
    int i,x,y,ans;
    for (i=0;i<6;i++)
        scanf("%d",&A[i]);
    ans=A[0]+A[1]+A[2];
    ans=ans*ans;
    ans-=A[0]*A[0];
    ans-=A[2]*A[2];
    ans-=A[4]*A[4];
    printf("%d",ans);
    return 0;
}
