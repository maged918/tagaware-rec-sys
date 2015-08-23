//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    #ifdef ACMTUYO 
        freopen("a.in", "r", stdin);
    #endif

    int n, x, a;
    cin >> n;
    vector<pair<int, int> > positivos, negativos;
    for (int i = 0; i < n; i++) {
        cin >> x >> a;
        if (x > 0)
            positivos.push_back(make_pair(x, a));
        else
            negativos.push_back(make_pair(x, a));
    }
    sort(positivos.begin(), positivos.end());
    sort(negativos.begin(), negativos.end());
    reverse(negativos.begin(), negativos.end());
    
    int minCant = min(positivos.size(), negativos.size());
    
    int result = 0;
    for (int i = 0; i < minCant; i++) {
        result += positivos[i].second;
        result += negativos[i].second;
    }
    
    if (positivos.size() < negativos.size())
        result += negativos[minCant].second;
    else if (positivos.size() > negativos.size())
        result += positivos[minCant].second;
    
    cout << result << endl;
    return 0;
}
