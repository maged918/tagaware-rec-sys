//Language: GNU C++


#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,m,k,l,d,e;


     long int a[200][200]={0};
    int b[200]={0};
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
    {

       cin>>a[i][j];

    }
    }




    for(int i=0;i<m;i++)
    {
        k=-1;
        for(int j=0;j<n;j++)
    {
       if(a[i][j]>k)
       {
           k=a[i][j];
           l=j;
       }
    }
    //cout<<"l="<<l;
    b[l]++;
    }
d=-1;

    for(int x=0;x<n;x++)
    {
        if(b[x]>d)
        {
            d=b[x];
            e=x;
        }
    }
    d=-1;
   // printf("%d\n",e+1);
   cout<<e+1;

    return 0;
}
