//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
struct array
{
    long long int flag;
    long long int cnt;
    long long int first;
    long long int last;
};
struct array t[1000005];
//long long int flag[1000005],cnt[1000005],first[1000005],last[1000005];
bool compare(const array &a,const array &b)
{
    if(a.cnt!=b.cnt)
        return a.cnt>b.cnt;
    else
    {
        return a.last-a.first<b.last-b.first;
    }
}
int main() 
{
    long long int n,a[100005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<1000005;i++)
    {
        t[i].flag=0;
        t[i].cnt=0;
    }
    //memset(flag,0,sizeof(flag));
    //memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
    {
        t[a[i]].cnt++;
        if(t[a[i]].flag==0)
        {
            t[a[i]].first=i;
            t[a[i]].last=i;
            t[a[i]].flag=1;
        }
        else
        {
            t[a[i]].last=i;
        }
    }
    sort(t,t+1000005,compare);
    cout<<t[0].first+1<<" "<<t[0].last+1<<endl;

    return 0;
}