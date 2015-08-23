//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <cmath>
long long num[100005];
long long ans[100005];
long long Ans[100005];
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long Xmin = 99999999999LL, Xmax = -999999999999LL;

    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        Xmin = min(Xmin, num[i]);
        Xmax = max(Xmax, num[i]);
    }

    Ans[0] = num[1] - num[0];
    ans[0] = num[n - 1] - num[0];

    for(int i = 1; i < n - 1; i++)
    {
        ans[i] = max(abs(num[i] - Xmin), abs(num[i] - Xmax));
        Ans[i] = min(num[i] - num[i - 1], num[i + 1] - num[i]);
    }

    ans[n - 1] = num[n - 1] - num[0];
    Ans[n - 1] = num[n - 1] - num[n - 2];

    for(int i = 0; i < n; i++)
    {
        cout << Ans[i] << " " << ans[i] << endl;
    }
}
