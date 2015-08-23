//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define nn 300010
int n,m;
char s[nn];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%s",s+1);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(s[i]=='.'&&s[i-1]=='.')
                ans++;
        }
        s[0]='#';
        s[n+1]='#';
        while(m--)
        {
            int a;
            char ch[2];
            scanf("%d%s",&a,&ch);
            if(s[a]=='.'&&ch[0]!='.')
            {
                if(s[a-1]=='.'&&s[a+1]=='.')
                    ans-=2;
                else if(s[a-1]=='.'||s[a+1]=='.')
                    ans-=1;
                s[a]=ch[0];
            }
            else if(s[a]!='.'&&ch[0]=='.')
            {
                if(s[a-1]=='.'&&s[a+1]=='.')
                    ans+=2;
                else if(s[a-1]=='.'||s[a+1]=='.')
                    ans+=1;
                s[a]=ch[0];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
