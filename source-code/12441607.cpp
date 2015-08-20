//Language: GNU C++


#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    long long t, s, q;
    cin >> t >> s >> q;
    int ans = 0;
    while (s < t){
        ans++;
        s = s * q;
    }
    cout << ans;
    return 0;
}
