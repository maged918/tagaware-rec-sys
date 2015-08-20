//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <set>
using namespace std;

#define trace(x) cerr << #x << "=" << x <<endl;
#define track(x, n) {cerr << #x << ":" << endl; for (int i = 0; i < n; i++) {cerr << x[i] << " ";} cerr << endl;}

string toString(int temp)
{
    string s;
    while (temp) {
        s.push_back((temp & 1) + '0');
        temp >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

#define abs(x) (((x) > 0)? (x): (-(x)));

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> S;
    int minSize = 105;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        S.push_back(toString(temp));
        minSize = min(minSize, (int)S[i].size());
    }
    int maxPrefix = 0;
    for (int i = 0; i < minSize; i++) {
        char bit = S[0][i];
        bool flag = true;
        for (int j = 1; j < n; j++) {
            if (S[j][i] != bit){
                flag = false;
                break;
            }
        }
        if (flag) {
            maxPrefix = i;
        } else {
            break;
        }
    }
    int operations = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (j = 0; j <= maxPrefix; j++);
        bool flag = false;
        for (; j < S[i].size(); j++) {
            if (S[i][j] == '1') {
                operations += S[i].size() - j;
                pos.push_back(j);
                flag = true;
                break;
            }
        }
        if (!flag) {
            pos.push_back(S[i].size());
        }
    }
    /*cout << operations << endl;
    for (int i = 0; i < pos.size(); i++) {
        cout << pos[i] << " ";
    }
    cout << endl;*/
    sort(pos.begin(), pos.end());
    int median = pos[pos.size() / 2];
    for (int i = 0; i < pos.size(); i++) {
        operations += abs(pos[i] - median);
    }
    cout << operations << endl;
}
