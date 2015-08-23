//Language: GNU C++


/*
    Name: Domestic Networks
    Copyright: @lzt2002
    Author: lzt2002
    Date: 20/07/15 20:08
    Description: POJ
*/

#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define havetxt 0
#define shuru "input.txt"
#define shuchu "output.txt"
#define inf 0x7fffffff
#define esp 1e-9

typedef long long ll;

int n;
bool flag;

void init()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            flag=1;
        }
    }
    
    if(flag)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<1<<endl;
    }
}

int main()
{
    init();
    
    return 0;
}