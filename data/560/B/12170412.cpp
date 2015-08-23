//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define PRINT_VAR(var,format) printf (#var "=" format "\n", (var))
#define LOCAL 0

const int max_sum = 1000000;

int main()
{
    #if LOCAL == 1
      freopen("input.txt", "rt", stdin);
      freopen("output.txt", "wt", stdout);
    #endif
    
    int a1, b1;
    scanf("%d%d", &a1, &b1);
    
    int a2, b2;
    scanf("%d%d", &a2, &b2);
    
    int a3, b3;
    scanf("%d%d", &a3, &b3);
    
    if (a1 >= a2 && b1 >= b2)
    {
        int da = a1 - a2,
            db = b1 - b2;
        if (a3 <= da && b3 <= b1 || a3 <= b1 && b3 <= da ||
            a3 <= db && b3 <= a1 || a3 <= a1 && b3 <= db)
        {
            printf("YES");
            return 0;
        }
    }
    
    swap(a1, b1);
    
    if (a1 >= a2 && b1 >= b2)
    {
        int da = a1 - a2,
            db = b1 - b2;
        if (a3 <= da && b3 <= b1 || a3 <= b1 && b3 <= da ||
            a3 <= db && b3 <= a1 || a3 <= a1 && b3 <= db)
        {
            printf("YES");
            return 0;
        }
    }
    
    printf("NO");
     
    return 0;
}
