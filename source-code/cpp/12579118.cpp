//Language: GNU C++


/* 
 * File:   main.cpp
 * Author: mo3ath
 *
 * Created on August 17, 2015, 8:44 PM
 */
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int s ,t ,q;
    cin>>t>>s>>q;
    int i=1;
    int r=q*s;
    while(r<t)
    {
        r*=q;
        i++;
    }
    cout<<i;
    return 0;
}

