//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
void solve(int l,int r,char s[])
{
    int len=r-l+1;
    if(len%2)
        return ;
    int mid=(l+r)>>1;
    solve(l,mid,s);
    solve(mid+1,r,s);
    int flag=0;
    for(int i=l;i<=mid;i++)
    {
        if(s[i]==s[i+len/2])
            continue;
        else if(s[i]<s[i+len/2])
            break;
        else
        {
            flag=1;
            break;
        }
    }
    if(!flag)
        return ;
    for(int i=l;i<=mid;i++)
        swap(s[i],s[i+len/2]);
}
int main()
{
    scanf("%s%s",a,b);
    int L=strlen(a);
    solve(0,L-1,a);
    solve(0,L-1,b);
    if(strcmp(a,b)==0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
