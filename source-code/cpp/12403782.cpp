//Language: GNU C++11


//
//  main.cpp
//  E
//
//  Created by luras on 15/7/23.
//  Copyright (c) 2015年 luras. All rights reserved.
//

#define ms(x, y) memset(x, y, sizeof(x))
#define mc(x, y) memcpy(x, y, sizeof(x))
#define ls o << 1
#define rs o << 1 | 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<list>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
const int N = 2e5;
const double PI = acos(-1.0);
typedef long long LL;
const LL Z = 1e9 + 7;

int n, m, Q, i, j, t, c[N + 100];
LL f[N + 100], fac[N + 100], inv[N + 100];
LL ans;
bool e[N + 100];


struct A
{
    LL x, y;
}a[N];

void init()
{
    int i, j;
    t = 0;
    for(i = 2; i <= N; i ++){
        if(!e[i]){
            c[++ t]=i;
            for(j = i; j <= N; j +=i){
                e[j] = 1;
            }
        }
    }
}


LL Cal(LL n, LL k){
    LL  ans = 1;
    for(int i = 1; i <= t; i ++){
        if(c[i] > n) return ans;
        LL x = n; LL y = k; LL z = n - k;
        LL t1 = 0; LL t2 = 0; LL t3 = 0;
        while(x){
            t1 += x / c[i];
            x /= c[i];
        }
        while(y){
            t2 += y / c[i];
            y /= c[i];
        }
        while(z){
            t3 += z / c[i];
            z /= c[i];
        }
        for(int j = 1; j <= t1 - t2 - t3; j ++){
            ans = ans * c[i] % Z;
        }
    }
    return ans;
}

//  (x/y) %Z == x^(y-2) %Z;

LL quickmul(LL x, LL y)
{
    LL ans = 1;
    while(y){
        if(y & 1) ans = (ans * x) % Z;
        y >>= 1;
        x = (x * x) % Z;
    }
    return ans;
}


LL inverse(LL x)
{
    return quickmul(x, Z  - 2);
}



void it()           //预处理逆元  
{
    fac[1] = 1;inv[1] = 1; inv[0] = 1;
    for(int i = 2; i <= N; i ++){
        fac[i] = fac[i - 1] * i % Z;
        inv[i] = inverse(fac[i]);
    }
    
}



int cmp(A a, A b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    
    it();
    while(~ scanf("%d%d%d", &n, &m, &Q)){
        for(i = 1; i <= Q; i ++){
            scanf("%I64d%I64d", &a[i].x, &a[i].y);
        }
        sort(a + 1, a + Q + 1, cmp);
        ans = ((fac[n + m - 2] * inv[n - 1]) % Z) * inv[m - 1] % Z;
        //ans = Cal(n + m - 2, n - 1);
        ms(f,0);
        for(i = 1; i <= Q; i ++){
            //f[i] = (f[i] + Z + Cal(a[i].x + a[i].y - 2, a[i].x - 1))%Z;
            LL tmp = ((fac[a[i].x + a[i].y - 2] * inv[a[i].x - 1]) % Z) * inv[a[i].y - 1] % Z;
            f[i] = (f[i] + Z + tmp) % Z;
            for(j = i + 1; j <= Q; j ++){
                if(a[j].x >= a[i].x && a[j].y >= a[i].y){
                    //f[j] = (f[j] + Z * Z - f[i] * Cal(a[j].x - a[i].x + a[j].y - a[i].y, a[j].x - a[i].x)) % Z;
                    LL tmp = ((fac[a[j].x + a[j].y - a[i].x - a[i].y] * inv[a[j].x - a[i].x]) % Z) * inv[a[j].y - a[i].y] % Z;
                    f[j] = (f[j] + Z * Z -f[i] * tmp) % Z;
                }
            }
        }
        
        for(i = 1; i <= Q; i ++){
            //ans = (ans + Z * Z - f[i] * Cal(n + m - a[i].x - a[i].y, n - a[i].x)) % Z;
            LL tmp = ((fac[n + m - a[i].x - a[i].y] * inv[n - a[i].x]) % Z) * inv[m - a[i].y] % Z;
            ans = (ans + Z * Z - f[i] * tmp) % Z;
        }
         
       
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
 
 题意:
 
 类型:
 
 分析:
 
 优化:
 
 trick:
 
 数据:
 
 Sample Input
 3 4 2
 2 2
 2 3
 
 100 100 3
 15 16
 16 15
 99 88
 
 Sample Output
 2
 545732279
 
 */

