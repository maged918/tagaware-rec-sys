//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l;
    char c;
    int ans = 0;
    int ans1 = 0;
    bool arr[1000005] = {0};

    cin >> n;

    while(n--)
    {
        cin >> c >> l;

        if(c == '+')
        {
            ans1++;
            arr[l] = 1;
            ans = max(ans, ans1);
        }
        else if(arr[l] == 1)
        {
            ans1--;
            arr[l] = 0;
        }
        else
            ans++;
    }
    cout << ans << endl;

    return 0;
}
