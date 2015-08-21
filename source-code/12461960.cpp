//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define LiangJiaJun main
#define MOD 1000000007
using namespace std;
int n;
vector<int>vec,pos;
int a[100004],ve[100004];
int LiangJiaJun(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=n&&a[i]>=1)ve[a[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(!ve[i])vec.push_back(i);

    int t=0,be=0;
    for(int i=1;i<=n&&be<vec.size();i++){
        if(a[i]<1||a[i]>n)a[i]=vec[be++];
        else if(ve[a[i]]>1){
            --ve[a[i]];a[i]=vec[be++];
        }
    }
    for(int i=1;i<n;i++)printf("%d ",a[i]);printf("%d\n",a[n]);
	return 0;
}
