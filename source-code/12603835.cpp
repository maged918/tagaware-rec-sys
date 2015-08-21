//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int i, j, n;
    int a1, a2, b1, b2, c1, c2;
    int x, y, z, t;
    while(scanf("%d", &n) != EOF){
        scanf("%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2);
        t = c1 + b1;
        x = a2;
        if(n - t < x)x = n - t;
        n = n - x;
        t = c1;
        y = b2;
        if(n - t < y)y = n - t;
        z = n - y;
        printf("%d %d %d\n", x, y, z);
    }
    return 0;
}

 	  			   			  								 		 	  	