//Language: GNU C++


#include <iostream>
using namespace std;

int main() {
    int m,n,i,j,max=-1,vote,k;
    cin>>n>>m;
    int a[m+1];
    int b[101]={0};
    for(i=1;i<=m;i++){
        max=-1;
        for(j=1;j<=n;j++){
            cin>>vote;
            if(vote>max){
                max=vote;
                k=j;
            }
        }
        a[i]=k;
        b[a[i]]++;
    }
    max=-1;
    for(i=1;i<101;i++){
        if(b[i]>max){
            max=b[i];
            k=i;
        }
    }
    cout<<k<<"\n";
    return 0;
}