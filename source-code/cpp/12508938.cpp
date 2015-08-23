//Language: GNU C++


//
//  main.cpp
//  cf_316_b
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
    int m,n,ans,mid;
    cin>>n>>m;
    
    if (n==1)
    {
        cout<<"1";
        return 0;
    }
    
    
    if (n%2==0)
    {
        mid = n/2;
        if (m<=mid)
            ans = m+1;
        else
            ans = m-1;
        
    }
    else
    {
        mid = n/2 + 1;
        if (m<mid)
            ans = m+1;
        else
            ans = m-1;
    }

    cout<<ans;
    
    return 0;
}
