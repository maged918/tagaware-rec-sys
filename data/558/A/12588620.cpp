//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int a,b;
    pair<int,int>x[10001];
    pair<int,int>y[10001];
    int k1 = 0, k2 = 0;
    for(int i = 0; i < t; i++){
        cin >> a;
        cin >> b;
        y[k2].first = a;
        x[k1].first = a;
        if(a > 0){
            x[k1++].second = b;
        }
        else{
            y[k2++].second = b;
        }
    }
    sort(x,x+k1);
    sort(y,y+k2);
    int m,n;
    int sum = 0;
    if(k1 > k2){
        m = k2;
        n = k2+1;
        for(int i = 0; i < m; i++){
            sum = sum + y[k2-i-1].second;
        }
        for(int i = 0; i < n; i++){
            sum = sum + x[i].second;
        }
    }
    else if(k1 < k2){
        m = k1;
        n = k1+1;
        for(int i = 0; i < n; i++){
            sum = sum + y[k2-i-1].second;
        }
        for(int i = 0; i < m; i++){
            sum = sum + x[i].second;
        }
    }
    else if(k1 == k2){
        m = n = k1;
        for(int i = 0; i < m; i++){
            sum = sum + y[k2-i-1].second;
        }
        for(int i = 0; i < n; i++){
            sum = sum + x[i].second;
        }
    }
    cout << sum << endl;
    return 0;
}