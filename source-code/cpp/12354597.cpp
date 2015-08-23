//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, a[MAXN];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    cout << a[2] - a[1] <<" "<< a[n] - a[1] <<endl;
    for(int i = 2; i < n; i ++)
        cout << min( a[i + 1] - a[i], a[i] - a[i-1])<<" "<< max(a[n] - a[i], a[i] - a[1])<<endl;
    cout << a[n] - a[n - 1] <<" "<< a[n] - a[1];
    return 0;
}
