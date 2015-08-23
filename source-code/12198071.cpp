//Language: GNU C++


//بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;
int w, h, a, b, a2, b2;
bool rotateup() {
    int s = b + a2;
    return h >= a && h >= b2 && w >= s;
}
bool rotaterright() {
    int s = a + b2;
    return h >= b && h >= a2 && w >= s;
}
bool rotatedown() {
    int s = a + b2;
    return h >= s && w >= a2 && w >= b;
}
bool rotateleft() {
    int s = b + a2;
    return w >= a && h >= s && w >= b2;
}
bool check(){
    int s=a+a2;
    return w>=b && w>=b2 && h>=s;
}
bool check2(){
    int s=b+b2;
    return h>=a && h>=a2 && w>=s;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    cin >> w >> h >> a >> b >> a2 >> b2;
    if (w >= a && w >= a2 && (b + b2) <= h)
        cout << "YES\n";
    else if (h >= b && h >= b2 && w >= a + a2)
        cout << "YES\n";
    else if (rotateup() || rotaterright() || rotatedown() || rotateleft() || check() || check2())
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
