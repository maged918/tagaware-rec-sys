//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool ispalindr(int a)
{
    char c[10];
    itoa(a, c, 10);
    string s = c;
    return s==string(s.rbegin(), s.rend());
}

bool issimple(int a)
{
    if(a<2)
        return false;
    for(int i=2; i<=a/i; ++i)
        if(a%i==0)
            return false;
    return true;
}

int main()
{
    unsigned long long p, q, pc=0, sc=0, mn=0;
    cin>>p>>q;
    for(int i=1; i<1200000 ; ++i)
    {
        if(ispalindr(i))
            ++pc;
        if(issimple(i))
            ++sc;
        if(q*sc<=p*pc)
            mn=i;
    }
    cout<<mn<<endl;
    return 0;
}
