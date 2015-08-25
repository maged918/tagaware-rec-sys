//Language: GNU C++11


#include <iostream>

using namespace std;

int main() {
    int a1, b1, a2, b2, a3, b3;

    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    int xdim1[4] = {a2, a2, b2, b2};
    int ydim1[4] = {b2, b2, a2, a2};
    int xdim2[4] = {a3, b3, a3, b3};
    int ydim2[4] = {b3, a3, b3, a3};

    bool ok = false;

    for (int i = 0; i < 4; i++) {
        if (xdim1[i] + xdim2[i] <= b1) {
            if (ydim1[i] <= a1 && ydim2[i] <= a1) {
                ok = true;
                break;
            }
        }

        if (ydim1[i] + ydim2[i] <= a1) {
            if (xdim1[i] <= b1 && xdim2[i] <= b1) {
                ok = true;
                break;
            }
        }
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}