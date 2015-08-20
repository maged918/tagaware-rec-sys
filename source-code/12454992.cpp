//Language: GNU C++11


#include <iostream>

#include <algorithm>

#include <cmath>

#include<stdio.h>
#include<string.h>
using namespace std;
const int MAXN = 4000;
long long data[MAXN+10][MAXN+10];
const long long  mo = 1e9 + 7;
void haha(int m, int n)
{
    long long int min, i, j;
    memset(data, 0, sizeof(data));
    data[0][0] = 1;

    for(int i = 1; i <= m; ++i )
     {
        if( i < n ) 
        min = i;
        else 
        min = n;

        for( j = 1; j <= min; ++j )
         {
            data[i][j] = ((long long)j * data[i - 1][j] % mo + data[i - 1][j - 1]) % mo;
        }
    }
}
int main()
{
    int n;
    haha(4000,4000);
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+(data[n][i]*i%mo))%mo;
        
    }
    cout<<ans<<endl;
}
