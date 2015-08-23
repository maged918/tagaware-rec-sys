//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    int a[100100];
    int pos[1000100];
    int Hash[1000010];
    cin>>n;
    int num=0;
    memset(Hash,0,sizeof Hash);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        Hash[a[i]]++;
        if (Hash[a[i]]==1) pos[a[i]]= i;
        num=max(num,Hash[a[i]]);
    }
    int stari;
    int endi;
    int lenmin=9999999;
     for (int i=n-1;i>=0;i--)
     {
         if (Hash[a[i]]==num)
         {
             if (i-pos[a[i]]<=lenmin)
             {
                 stari=pos[a[i]];
                 endi=i;
                 lenmin=i-pos[a[i]];
             }
            Hash[a[i]]--;
         }
     }
    printf("%d %d\n",stari+1,endi+1);
    return 0;
}
