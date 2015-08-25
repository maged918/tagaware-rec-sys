//Language: GNU C++11


#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool flag = false;
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        if (x==1) flag = true;
    }
    if (flag) cout << -1 << endl;
    else      cout << 1 << endl;
    return 0;
}
