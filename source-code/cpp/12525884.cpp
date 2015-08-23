//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define PR(x) { cout << #x << " = "; cout << (x) << endl; }
#define PRF(x,n) { cout << #x << " = "; FOR(_,0,n) cout << x[_] << ' '; cout << endl; }

int main()
{
    ios :: sync_with_stdio(false);
    int n,m;
    string S;
    int res=0;
    
    cin>>n>>m;
    cin>>S;
    FOR(i,0,n-1){
        if (S[i]=='.' && S[i+1]=='.'){
            res++;
        }
    }
    int pos; char rep;
    while(m--){
        cin>>pos>>rep;
        pos--;

        if(S[pos]=='.'){
            if(pos>0 && S[pos-1]=='.')
                res--;
            if(pos<n-1 && S[pos+1]=='.')
                res--;
        }
        
        S[pos]=rep;
        if(S[pos]=='.'){
            if(pos>0 && S[pos-1]=='.')
                res++;
            if(pos<n-1 && S[pos+1]=='.')
                res++;
        }
        
        cout<<res<<endl;
    }

}