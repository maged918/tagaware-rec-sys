//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int m[1005];

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&m[i]);
    }
    sort(m,m+n);
    if (m[0] == 1)
        printf("-1\n");
    else
        printf("1\n");
    return 0;

}

 		 	 	     		  					 									