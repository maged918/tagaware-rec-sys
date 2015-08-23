//Language: GNU C++


#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<set>
using namespace std;
int stoi(string x){stringstream ss;ss<<x;int tmp;ss>>tmp;return tmp;}
string itos(int x){stringstream ss;ss<<x;return ss.str();}
#define SZ(n)  (int)n.size()
#define dump(x) cerr<<#x<<" = "<<(x)<<endl;
#define debug(x)cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define mp make_pair
#define pb push_back
    const int INF=1300000;
    bool is[INF];
    int prime[INF];
    int pan  [INF];
    int ts,sum=0;
    bool f;
    string tmp;
    int main(){
        for(int i=0;i<INF;i++)is[i]=1;
        for(int i=2;i*i<INF;i++){
            if(is[i]){
                for(int j=0;i*(j+2)<INF;j++){
                    is[i*(j+2)]=0;
                }
            }
        }
        
        for(int i=2;i<INF;i++){
            if(is[i]){sum++;}
            prime[i]=sum;
        }
        sum=0;
        for(int i=1;i<INF;i++){
            tmp=itos(i);
            ts=tmp.size();
            f=1;
            for(int j=0;j<ts/2;j++)if(tmp[j]!=tmp[ts-j-1])f=0;
            if(f){sum++;}
            pan[i]=sum;
        }
        
        
        int ans=0;
        int c1,c2;
        double p,q;
        cin>>p>>q;
        for(int i=1;i<INF;i++){
            //c1=0,c2=0;
            //for(int j=1;j<=i;j++)if(prime[j])c1++;
            //for(int j=1;j<=i;j++)if(pan[j])c2++;
            //cout<<i<<" "<<prime[i]<<" "<<pan[i]<<endl;
            if(prime[i] <=((p/q)*(double)pan[i])){ans=i;}
        }
        if(ans==0||ans==INF-1)cout<<"Palindromic tree is better than splay tree"<<endl;
        else    cout<<ans<<endl;
    return 0;
}