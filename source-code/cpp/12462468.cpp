//Language: GNU C++


//#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
    double s, t, q, ans=1;
    cin >> t>> s>> q;
    s*=q;
    while(t>s){
         s*=q;
         ans++;
    }
    cout<< ans;
}
