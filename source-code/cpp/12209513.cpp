//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int a[8];
int flag;
void input(){
    for (int i=2;i<=6;i++){
        cin >> a[i];
    }

}

int add(int l,int r,int t){
    if (l<r)
        swap(l,r);
    int x = 0;
    for (int i=1;i<=r;i++){
        x+= i+t;
    }
    x += (r+t) * (l - r);
    //cout << "x = " << x << endl;
    return x*2;
}

void solve(){
    flag = 0;
    int x = min(a[3],a[5]);
    int sum = a[1] + a[4];
    sum += add(a[2],a[6],a[1]);

    sum += add(x,x,a[4]);
    sum -= (x+a[4])*2;
    cout << sum << endl;
}

int main(){
    //freopen("1.txt","r",stdin);
    while(cin >> a[1]){
        input();
        solve();
    }
}
