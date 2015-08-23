//Language: GNU C++


#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>
using namespace std;
string s, t;

bool ok(string a, string b)
{
    int n = a.length(), m = b.length();

    if(a == b)
    {
        return 1;
    }
    if(n%2==1 || n!=m)
    {
        return 0;
    }
    if((ok(a.substr(0, n/2), b.substr(m/2)) && ok(a.substr(n/2), b.substr(0, m/2)))||(ok(a.substr(0, n/2), b.substr(0,m/2)) && ok(a.substr(n/2), b.substr(m/2))))
        return 1;
    else
        return 0;
        }
int main ()
{
   // #ifdef saltanat
    //freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    //#endif
    cin >> s >> t;
    cout<<(ok(s, t)?"YES":"NO");
   // system("pause");
    return 0;
}
