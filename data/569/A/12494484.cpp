//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int t,s,q,kol = 0;
    cin>>t>>s>>q;
    while (s<t)
    {
        kol++;
        s=s*q;

    }
    cout<<kol;
    return 0;
}
