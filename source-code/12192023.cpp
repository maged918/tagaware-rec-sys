//Language: GNU C++


#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
char change(char s[],int N)
{
    int i,j;
    if(N%2)
        return *s;
    int l=N/2;
    change(s,l);
    change(s+l,l);
    if(strncmp(s,s+l,l)>0)
    {
        char temp;
        for(i=0;i<l;i++)
        {
            temp=s[i];
            s[i]=s[i+l];
            s[i+l]=temp;
        }
    }
    return *s;
}
int main()
{
    char s1[200010],s2[200010];
    int i,j;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int l=strlen(s1);
        *s1=change(s1,l);
        *s2=change(s2,l);
        if(strncmp(s1,s2,l)==0)
            printf("YES\n");
        else printf("NO\n");
    }
}