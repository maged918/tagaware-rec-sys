//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int win[200];
int main(){
    int n,m;
    cin>>n>>m;
    long long x;
    while(m--){
        long long w=0,mx=-1;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x>mx){
                mx=x;
                w=i;
            }
        }
        win[w]++;
    }

    int w=0,mx=0;
    for(int i=0;i<n;i++){
        if(win[i] > mx){
            w=i;
            mx=win[i];
        }
    }
    cout<<w+1<<endl;
return 0;   
}