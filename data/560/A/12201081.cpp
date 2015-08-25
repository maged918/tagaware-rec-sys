//Language: GNU C++11


#include <bits/stdc++.h>

#define fu(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define mp make_pair
#define pb push_back
#define popb pop_back
#define ff first
#define ss second
    
using namespace std;


int main(){
    bool res = false;
    int n;
    cin >> n;
    while (n--){
        int a;
        cin >> a;
        res = res || (a == 1);
    }
    if (res)
        cout << -1;
    else
        cout << 1;
}
    
    
