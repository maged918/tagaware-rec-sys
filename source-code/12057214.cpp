//Language: GNU C++


#include <iostream>
#include <cstring>
using namespace std;
struct node{
    int start;
    int end;
    int times;
}num[1000005];

int main() {
    int n, t;
    cin >> n;
    for (int i = 0; i < 1000005; ++i) {
        num[i].start = -1;
        num[i].times = 0;
    }
    for (int i = 0; i< n; ++i) {
        cin >> t;
        num[t].times++;
        if (num[t].start == -1) num[t].start = i;
        num[t].end = i;
    }
    int max = 0, len = -1, maxi = -1;
    for (int i = 0; i < 1000005; ++i) {
        if (num[i].times > 0) {
            if (num[i].times > max) {
                max = num[i].times;
                len = num[i].end - num[i].start;
                maxi = i;
            }
            if (num[i].times == max) {
                if (len > num[i].end - num[i].start) {
                    maxi = i;
                    len = num[i].end - num[i].start;
                }
            }
        }
    }
    cout << num[maxi].start + 1 << " " << num[maxi].end + 1 << endl;
    return 0;
}