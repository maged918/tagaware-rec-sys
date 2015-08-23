//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std ;
int n ;
int a[2000] ;
int main()
{
    cin >> n ;
    for(int i = 0 ;i < n ; i++){
        cin >> a[i] ;
    }
    sort(a,a+n) ;
    if(a[0] == 1)cout << -1 ;
    else cout << 1 ;
    return 0;
}