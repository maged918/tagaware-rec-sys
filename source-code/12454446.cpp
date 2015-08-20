//Language: GNU C++


#include<iostream>
#include <map>
#include <cstring>
using namespace std;
long long int a[100001],b[100001];

int main()
{
    map <int, int> mp;
    map <int, int> ::iterator pos;
    memset(b, 0, sizeof(b));
    int c,d,i,j,n,k=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(i = 1; i <= n; i++) {
        if(mp[i] == 0) {
            b[k] = i;
            k++;
        }
    }
    k = 0;
    for(i = 0; i < n; i++) {
        if(n >= a[i]) {
                if(mp[a[i]] != 0) {
            mp[a[i]] = 0;
        }
        else {
            a[i] = b[k];
            k++;
        }
        }
        else {
            a[i] = b[k];
            k++;
        }
    }
    for(i=0;i<n;i++)
    {
        cout << a[i] << ' ' ;
    }
    return 0;


}
