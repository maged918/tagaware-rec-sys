//Language: MS C++


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int inf = 0x3f3f3f3f;
const int MAXN=1000000+10;

int a[1005];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];

    }

    sort(a,a+n);
    if(a[0]==1)
        cout<<"-1"<<endl;
    else
    cout<<"1"<<endl;




}
