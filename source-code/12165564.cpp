//Language: GNU C++


#include <iostream>
using namespace std;

int main() {

        int n;
        cin >> n;
        int a[n];
        int munf = 1;

        for (int i = 0; i < n; i++) {
                cin >> a[i];
                if (a[i] == 1) {
                        munf = -1;
                }
        }

        cout << munf << endl;

        return 0;
}
