//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int x[1000007]={0};
int main()
{
    int n,a,i,j,sum=0,sss=0;
    char s;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        getchar();
        scanf("%c %d",&s,&a);
        if(s=='+'){
            sss++;
            x[a]=1;
        }
        else if(s=='-' && x[a]==1){
            sss--;x[a]=0;
 
        }
        else if(s=='-' && x[a]==0){
            sum++;
 
        }
        sum=sum>=sss?sum:sss;
 
    }
    printf("%d",sum);
    return 0;}