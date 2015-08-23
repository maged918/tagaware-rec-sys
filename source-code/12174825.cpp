//Language: GNU C++11


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    if (vec[0] == 1)
           cout << -1 << endl;
    else
           cout << 1 << endl;

    return 0;
}

