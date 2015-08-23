//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
map<long long,long long>b,f;
long long ar[200100],n , k , c;
int main()
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> ar[i];
        f[ar[i]]++;
    }
    for(int i = 0 ; i < n ; i++)
    {
        f[ar[i]]--;
        if(ar[i]%k==0)
            c += f[ar[i]*k]*b[ar[i]/k];
        b[ar[i]]++;
    }
    cout << c;
}