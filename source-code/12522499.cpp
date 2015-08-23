//Language: GNU C++


#include <iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long

int main() {
    int n,m;
    cin>>m>>n;
    
    map<int,int> nii;
    for(int i=1;i<=n;i++){
        int x=0;
        ll a,cnt=-1;
        for(int j=1;j<=m;j++){
            cin>>a;
            if(a>cnt){
                cnt=a;
                x = j;
            }
        }
        nii[x]++;
    }
    map<int,int>::iterator itr;
    int x=-1,cnt=-1;
    for(itr=nii.begin();itr!=nii.end();itr++){
        if(itr->second >cnt){
            x = itr->first;
            cnt = itr->second;
        }
    }
    cout<<x<<endl;
    
}