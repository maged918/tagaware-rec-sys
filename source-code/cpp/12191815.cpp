//Language: GNU C++


/*************************************************************************
  > File Name: bb.cpp
  > Author: chbug
  > Created Time: 2015/7/23 ������ 8:59:53
*************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int a1, b1;

bool f(int a, int b)
{
    if ((a1 >= a && b1 >= b) || (b1 >= a && a1 >= b)) return true;
    return false;
}

int main()
{
    int a2, a3, b2, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    int flag = 0;
    if (f(a2+a3, max(b2, b3))) flag = 1;
    if (f(a2+b3, max(b2, a3))) flag = 1;
    if (f(b2+a3, max(a2, b3))) flag = 1;
    if (f(b2+b3, max(a2, a3))) flag = 1;
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

