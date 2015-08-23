//Language: GNU C++11


#include <bits/stdc++.h>

#define l(i,n) for(int i=0;i<n;i++)
#define	all( gg )	gg.begin(),gg.end()

#define pii pair<int,int>
#define DB()    cout<<"I'm in!"<<endl

typedef long long LL;

using namespace std;


int main(){
std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int n;
    cin>>n;
    int a[n];
    map<int,int> cnt;
    bool ekdominai[n+1];
    memset(ekdominai,1,sizeof(ekdominai));
    l(i,n){
        cin>>a[i],cnt[a[i]]++;
        if(a[i]<=n) ekdominai[a[i]]=0;
    }

    vector<int> nehi;
    l(i,n) if(ekdominai[i+1]) nehi.push_back(i+1);

    map<int,bool> taken;
    int nai=0;
    l(i,n){
        if(!taken[a[i]] && a[i]<=n) {cout<<a[i];taken[a[i]]=1;}
        else{
            cout<<nehi[nai];
            nai++;
        }
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;




return 0;
}
