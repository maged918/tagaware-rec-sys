//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 400000;
const int oo = 1e9;

char s[N];

int main()
{
    int n,m,i,k;
    char ch;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        int a=0,sum=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='.')
                    a++;
            else if(s[i]!='.' && s[i-1]=='.' && i!=0)
            {
                sum+=a-1;
                a=0;
            }
        }
        if(a!=0)
                sum+=a-1;

        while(m--)
        {
            scanf("%d %c",&k,&ch);
            if(s[k-1]=='.' && ch=='.')
            {
             printf("%d\n", sum);
             continue;
            }
            if(s[k-1]!='.' && ch!='.')
            {
                printf("%d\n", sum);
                continue;
            }

            s[k-1]=ch;
            if(ch!='.')
            {
                if(s[k]!='.' && s[k-2]!='.')
                sum=sum;
                else if(s[k]=='.' && s[k-2]=='.')
                sum=sum-2;
                else if(s[k]!='.' || s[k-2]!='.')
                sum=sum-1;
            }
            else
            {
                if(s[k]=='.' && s[k-2]=='.')
                    sum=sum+2;
                else if(s[k]!='.' && s[k-2]!='.')
                    sum=sum;
                else if(s[k]!='.' || s[k-2]!='.')
                    sum+=1;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}

			 	 					      	 	 				 		  	