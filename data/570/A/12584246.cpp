//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        int i,j;
        int k[100][100];
        int max;
        int p;
        int sum=0;
        int x[100];
        memset(x,0,100);
        for(i=0;i<m;i++){
                max = -1;
            for(j=0;j<n;j++){
                scanf("%d",&k[i][j]);
                if(k[i][j]>max){
                    max=k[i][j];
                    p=j;
                }
            }
            x[p]++;
        }
        max=0;
        for(i=0;i<n;i++){
            if(x[i]>max)
            {
                max=x[i];
                p=i;
            }
        }
        printf("%d\n",p+1);
    }
return 0;
}
