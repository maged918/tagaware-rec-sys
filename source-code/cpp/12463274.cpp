//Language: GNU C++


#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
const int N=10000000 +10;
vector <bool> pr(N-10,true);
bool pali (int n){
    int ch=n;
    int cur=0;
    while(ch>0){
        cur=cur*10 + (ch%10);
        ch/=10;
    }
    if(cur == n)
    return true;
    return false;
}
inline void build (){
    pr[1]=false;
    for (int i=2;i<=N-10;i++){
        if(pr[i]==true){
            if(i*1LL*i <= N-10){
                for (int j=i*i;j<=N-10;j+=i){
                    pr[j]=false;
                }
            }
        }
    }

}

int main(){
    int p,q;
    scanf("%d %d" , &p,&q);
    build();
    int kolpr=0;
    int kolpal=0;
    int last;
    double k=(1.0*p)/(1.0*q);
    for(int i=1;i<=N-10;i++){
        if (pr[i]==true){
            kolpr++;
        }
        if(pali(i)==true){
            kolpal++;
        }
        if(k*kolpal*1.0 >= kolpr*1.0){
            last=i;
        }

    }
    printf("%d" , last);

    return 0;
}
