//Language: GNU C++11


/* In the name of Allah */

#include<bits/stdc++.h>

using namespace std;

const int max_n=1e6+2e5+5;

int p[max_n];
bool check[max_n];
int q[max_n];
int main()
{
    int a,b;
    cin >> a>>b;
    for(int i=2;i<max_n;i++)
    {
        if(!check[i])
        {
            p[i]=p[i-1]+1;
            for(int j=2*i;j<max_n;j+=i)
                check[j]=1;
        }
        else
            p[i]=p[i-1];
    }
    for(int i=1;i<max_n;i++)
    {
        int id=i;
        int j=0;
        while(id!=0)
        {
            j=j*10 + id%10;
            id/=10;
        }
        if(i==j) q[i]=q[i-1]+1;
        else q[i]=q[i-1];
    }
    for(int i=max_n-5;i>0;i--)
    {
        if(b*p[i]<= a*q[i])
        {
            cout<< i;
            return 0;
        }
    }
}