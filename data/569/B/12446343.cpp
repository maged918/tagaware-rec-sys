//Language: GNU C++


#include<stdio.h>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;
int a[100003];
static int count1[100003];
int main()
{
    int n;
    scanf("%d",&n);

    vector<int> v,v2;

    memset(count1,0,sizeof(count1));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        count1[a[i]]++;
        if(count1[a[i]]>1 || a[i]>n)
        {
            v.push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(count1[i]==0)
        {
            v2.push_back(i);
        }

    }
    for(int i=0;i<v.size();i++)
    {
        a[v[i]]=v2[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }



    return 0;
}
