//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n/2 >= m){
        cout << min(m+1,n);
    }
    else cout << max(m-1,1);
    return 0;
}
