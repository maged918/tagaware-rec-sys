//Language: MS C++


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

int p, q;
const int n = 1200000;
vector<char> prime, rb;
vector<int> pi, rub;

int main()
{
    cin >> p >> q;
    prime.resize(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; ++i)
    if (prime[i])
    if (i * 1ll * i <= n)
    for (int j = i*i; j <= n; j += i)
        prime[j] = false;

    int x = 0;
    pi.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (prime[i]) x++;
        pi[i] = x;
    }
    
    rb.resize(10000000, false);
    for (int i = 1; i < 10; i++) {
        rb[i] = true;
        rb[10 * i + i] = true;
        for (int j = 0; j < 10; j++) {
            rb[i + 10 * j + 100 * i] = true;
            rb[i + 10 * j + 100 * j + 1000 * i] = true;
            for (int k = 0; k < 10; k++) {
                rb[i + 10 * j + 100 * k + 1000 * j + 10000 * i] = true;
                rb[i + 10 * j + 100 * k + 1000 * k + 10000 * j + 100000 * i] = true;
                for (int l = 0; l < 10; l++) {
                    rb[i + 10 * j + 100 * k + 1000 * l + 10000 * k + 100000 * j + 1000000 * i] = true;

                }
            }
        }
    }

    int y = 0;
    rub.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (rb[i]) y++;
        rub[i] = y;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (q*pi[i] <= p*rub[i]) res = i;
    }

    cout << res;
    cin >> p;
    return 0;
}
