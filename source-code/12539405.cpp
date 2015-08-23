//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<memory.h>
using namespace std;
int N,S,Max;
int a[1000010];
int main()
{
    while(scanf("%d",&N)!=EOF){
        S=0;Max=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<N;i++){
            char m;
            int n;
            cin>>m;
            scanf("%d",&n);
            if(m=='+'){
                S++;if(S>Max) Max=S;
                a[n]=1;
            }else{
                if(a[n]==0){
                    Max++;
                }else S--;
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}

		 				 	   		  	 			 	  	  	 	