//Language: GNU C++11


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool hasOne = false;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            hasOne = true;
        }
    }

    if (hasOne) {
        cout << -1 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}
