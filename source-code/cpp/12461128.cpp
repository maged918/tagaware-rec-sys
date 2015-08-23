//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define lld long long int

int main()
{
    int t,s,q,i=0,j;
    cin >> t >> s >> q;
    j=s;
    while(j<t)
    {
        i++;
        j=q*j;
        //cout << "i " << i << " " << j << endl;
    }
    cout << i << endl;
    return 0;
}