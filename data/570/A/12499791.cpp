//Language: GNU C++


//
//  main.cpp
//  cf_316_a
//
//  Created by Sidharth Raja on 13/08/15.
//  Copyright (c) 2015 Sidharth Raja. All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    
    vector<int> curr(n,0),wins(n,0);
    
    for (int i=0; i<m; i++)
    {
        int t = 0;
        for (int j=0; j<n; j++)
        {
            scanf("%d",&curr[j]);
            if (curr[j]>curr[t])
                t = j;
        }
        wins[t]++;
    }
    
    
    int winner2 = 0;
//    cout<<endl<<m<<endl;
    for (int i=0; i<n; i++)
    {
//        cout<<wins[i]<<" ";
        if (wins[i]>wins[winner2])
             winner2 = i;
    }
    
    cout<<winner2+1;
    
    return 0;
}

