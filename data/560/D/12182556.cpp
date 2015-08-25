//Language: GNU C++


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

char stra[200005];
char strb[400005];

bool isEqual(char* a,char *b,int len){
    //if(len<50000)puts("working");
    bool flag=true;
    for(int i=0;i<len&&flag;i++){
        if(a[i]!=b[i]) flag=false;
    }
    if(flag)return true;
    if(len&1) return false;
    return (isEqual(a,b+len/2,len/2)&&isEqual(a+len/2,b,len/2)) || (isEqual(a,b,len/2)&&isEqual(a+len/2,b+len/2,len/2));
}

int main(){
    gets(stra);
    gets(strb);
    int len=strlen(strb);
    
    puts(isEqual(stra,strb,len)?"YES":"NO");
    return 0;
}
