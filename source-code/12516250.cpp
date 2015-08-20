//Language: GNU C++


#include <iostream>
#include<stdio.h>
#include<map>
#include <iterator>
using namespace std;
char cad[300050];
int main()
{
    int m,n,aux=0,idx,fs=0;
    char car;
    scanf("%d%d",&n,&m);
    scanf("%s",cad);
    for(int i=0;i<n;i++){
        if(cad[i]=='.'){
            aux++;
        }
        else{
            if(aux>=1)
            fs+=aux-1;
            aux=0;
        }
    }
    if(aux>=1)fs+=aux-1;
    while(m--){
        int idx;
        scanf("%d %c",&idx,&car);
        idx--;
        if(car=='.'&& cad[idx]!='.'){
            if(idx!=0 && cad[idx-1]=='.') fs++;
            if(idx!=n-1&&cad[idx+1]=='.') fs++;
        }
        if(car!='.' && cad[idx]=='.'){
            if(idx!=0 && cad[idx-1]=='.') fs--;
            if(idx!=n-1 && cad[idx+1]=='.') fs--;
        }
        cad[idx]=car;
        printf("%d\n",fs);
    }

    return 0;
}
