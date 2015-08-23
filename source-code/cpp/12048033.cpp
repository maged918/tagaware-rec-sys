//Language: GNU C++11


#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;

#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2.0*acos(0.0))
#define ERR         1e-5
#define PRE         1e-8
#define SZ(s)       ((long long int)s.size())
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<long long int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<long long int>::iterator
#define SI          set<long long int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)

#define pb          push_back

typedef struct tree
{

    int x;
    int a;
}tree;
int main()
{
    int n;
    cin>>n;
    int i;
    tree pob[n+1],nob[n+1];
    //mem(positive,0);
    //mem(negative,0);
    int pos=0,neg=0;
    int xx,aa;
    fr(i,1,n)
    {
        cin>>xx>>aa;
        if(xx>0)
        {
            pob[pos].x=xx;
            pob[pos].a=aa;
            pos++;
        }
        else
        {

            nob[neg].x=xx;
            nob[neg].a=aa;
            neg++;
        }
    }
    int j;
    fr(i,0,pos-2)
    {
        fr(j,i+1,pos-1)
        {
            if(pob[i].x>pob[j].x)
            {
                tree temp;
                temp=pob[i];
                pob[i]=pob[j];
                pob[j]=temp;
            }
        }
    }

    fr(i,0,neg-2)
    {
        fr(j,i+1,neg-1)
        {
            if(nob[i].x<nob[j].x)
            {
                tree temp;
                temp=nob[i];
                nob[i]=nob[j];
                nob[j]=temp;
            }
        }
    }
    int sum=0;
    if(pos==neg)
    {
        sum=0;
        fr(i,0,pos-1)
        {
            sum+=pob[i].a;
            sum+=nob[i].a;
            //cout<<pob[i].a<<" "<<nob[i].a<<endl;
        }
    }
    else if(pos<neg)
    {
        sum=0;
        fr(i,0,pos-1)
        {
            sum+=pob[i].a;
            //cout<<pob[i].a<<endl;
        }
        fr(i,0,pos)
        {
            sum+=nob[i].a;
            //cout<<nob[i].a<<endl;
        }
    }
    else if(neg<pos)
    {
        sum=0;
        fr(i,0,neg-1)
        {
            sum+=nob[i].a;
            //cout<<nob[i].a<<endl;
        }
        fr(i,0,neg)
        {
            sum+=pob[i].a;
            //cout<<pob[i].a<<endl;
        }
    }
    cout<<sum<<endl;
    return 0;
}
