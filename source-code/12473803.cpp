//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<bitset>
#include<list>
const double inf=1e20;
using namespace std;
const int md=1000000007;
int n,C[4010][4010],B[4010];
void pre()
{
     for (int i=0;i<=4000;i++) C[i][0]=1;
     for (int i=1;i<=4000;i++) for (int j=1;j<=4000;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%md;
}
int main(){
    pre();
    cin>>n;
    B[0]=1;
    for (int i=0;i<=n;i++)
    {
        for (int j=i+1;j<=n+1;j++)
        B[j]=(B[j]+(long long)B[i]*C[j-1][i])%md;
    }
    cout<<(B[n+1]-B[n]+md)%md;
    return 0;
}
