//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
int main()
{
    int n,m,maxn,mark,i,j,temp,cot;
    multiset<int>a;
    multiset<int>::iterator it;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        maxn=-1;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&temp);
            if(temp>maxn)
            {maxn=temp;mark=j;}
        }
        a.insert(mark);
    }
    maxn=-1;
    for(it=a.begin();it!=a.end();it++)
    {
        //cout<<(*it)<<endl;
        cot=a.count(*it);
        if(cot>maxn)
            {maxn=cot;mark=*it;}
    }
    printf("%d\n",mark);
    return 0;
}
			  	 		 								  	 				   		