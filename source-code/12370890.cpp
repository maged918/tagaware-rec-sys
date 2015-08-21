//Language: GNU C++


//
//  main.cpp
//  cf.pi.d
//
//  Created by eycia on 6/8/15.
//  Copyright (c) 2015年 eycia. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
using namespace std;

set<int> mp;

int main(int argc, const char * argv[]) {
    int n, k, a, m, tmp;
    cin >> n >> k >> a;
    cin >> m;
    mp.insert(0);
    mp.insert(n+1);
    int rest = (n+1)/(a+1);
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        int le = *(--mp.lower_bound(tmp)), ri = *mp.lower_bound(tmp);
        int rr = (ri-le)/(a+1);
        int r2 = (ri-tmp)/(a+1) + (tmp-le)/(a+1);
        rest -= rr-r2;
        if (rest < k) {
            cout << i+1 << endl;
            return 0;
        }
        mp.insert(tmp);
    }
    cout << -1 << endl;
}
