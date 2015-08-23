//Language: GNU C++11


#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (b < f)
    {
        swap(f, b);
        swap(c, e);
    }
    cout << (2 * f * a + f * f + abs(b - f) * (2 * a + 2 * f) + 2 * c * d + c * c);

    
    return 0;
}
