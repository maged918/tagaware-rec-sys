//Language: GNU C++


#include<iostream>
#include<set>
#include<stack>
#include<map>
#include<iomanip>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<fstream>

#define ll long long
#define D double
#define F first
#define S second


using namespace std;

D dist (D x1, D y1, D x2, D y2 )
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
D area (D x1, D y1, D x2, D y2, D x3, D y3)
{
    double a = dist (x1,y1,x2,y2), b = dist (x1,y1,x3,y3),c = dist(x2,y2,x3,y3);
    double p = (a+b+c) /2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int s1[1000001],s2[1000001];
int main()
{
   // cin.tie(0);
    //ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
        string s;
    while(a[0]) s=(char)((a[0]%2)+48)+s,a[0]/=2;
    vector<string> aa;
    aa.push_back(s);
    for(int i=1;i<n;i++)
    {
        string s1;
        while(a[i]) s1=(char)((a[i]%2)+48)+s1,a[i]/=2;
        int j = 0;
        while(j<min(s1.size(),s.size()) && s[j]==s1[j]) j++;
        aa.push_back(s1);
        s = s.substr(0,j);
    }
    int mn=1e9;
    int mm = s.size();
    for(int i=0;i<20;i++)
    {
        int sm = 0;
        for(int j=0;j<n;j++)
            {
                if(aa[j].size()>=s.size())
                {
                    sm+= aa[j].size()-s.size();
                    int t;
                    for( t=mm;t<s.size();t++)
                    if(aa[j][t]=='1') break;
                    sm+=(s.size()-t)*2;
                }
                else
                    {

                    int t;
                    for( t=mm;t<aa[j].size();t++)
                    if(aa[j][t]=='1') break;
                    sm+=(aa[j].size()-t)+s.size()-t;
                    }
                    //cout<<sm<<endl;
            }
            //cout<<sm<<endl;
                    mn = min(mn,sm);
            s+='0';
    }
    cout<<mn;
}