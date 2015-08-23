//Language: GNU C++


#include<iostream>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<set>
#include<string.h>
#include<math.h>
#define MOD 1000000007
#define MIN -100000000
#define MAX 100000000
#define ll long long int
/* HOPE n WILL :)
    NGU :)
    _/\_    */
// MG

int a[1015];

int main()
{
    int n,i;
    int flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        flag=1;
    }
    if(flag==1)
    cout<<"-1\n";
    else cout<<"1\n";
    return 0;
}