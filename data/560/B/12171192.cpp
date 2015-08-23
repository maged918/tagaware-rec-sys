//Language: GNU C++11


//
//  main.cpp
//  yes
//
//  Created by Irina Korneeva on 22/07/15.
//  Copyright (c) 2015 Irina Korneeva. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c>> d >>e >>f;
    if(a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
    if(d > c)
    {
        int t = d;
        d = c;
        c = t;
    }
    if(f > e)
    {
        int t = f;
        f = e;
        e = t;
    }
   
    if(((a >= c + e) && b >= max(d, f)) || ((a >= c + f) && (b >= max(d, e))) || ((b >= c + e) && (a >= max(d, f))) || (b >= c + e && a >= max(d,f))
       ||((a >= max(c , e)) && b >= d+ f) || ((a >= max(c, f)) && (b >=(d+ e))) || ((b >= max(c , e)) && (a >= (d+ f))) || (b >= max(c , e) && a >= (d+f)))
        cout << "YES"; else cout << "NO";
    
}