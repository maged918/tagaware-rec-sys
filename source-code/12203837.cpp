//Language: GNU C++


//
//  main.cpp
//  df s
//
//  Created by hahaha on 15/6/22.
//  Copyright (c) 2015年 hahaha. All rights reserved.
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a[7];
    for(int i=0;i<6;i++)
        cin >> a[i];
    cout << (a[0]+a[1]+a[2])*(a[0]+a[1]+a[2])-a[0]*a[0]-a[4]*a[4]-a[2]*a[2]<<endl;
    return 0;
}