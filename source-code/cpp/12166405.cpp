//Language: GNU C++11


#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <cstring>
#include <map>


using namespace std;
#define MAXSIZE 27
#define pi 3.1415926536


int main()
{
    int n,minsum=0, ind = 0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % v[j] == 0)
            {
                ind = 1;
                break;
            }
        }
        if (ind == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}