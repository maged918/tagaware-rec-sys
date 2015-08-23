//Language: GNU C++11


#include <iostream>
using namespace std;

int main() {
    int t, s, q;

    cin >> t >> s >> q;

    int result = 1;
    int x = s * q;

    while (x < t) {
        ++result;
        s = x;
        x = s * q;
    }
    cout << result << '\n';

    return 0;
}
