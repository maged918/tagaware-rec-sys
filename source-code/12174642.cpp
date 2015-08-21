//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int a1,a2,a3,a4,a5,a6;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    cout << (a1+a2+a3)*(a1+a2+a3) - (a1*a1) - (a3*a3) - (a5*a5) << endl;
    return 0;
}
