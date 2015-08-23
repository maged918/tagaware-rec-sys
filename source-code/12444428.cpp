//Language: GNU C++11


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
using namespace std;

int main()
{
    double t, s, q;
    scanf("%lf%lf%lf", &t, &s, &q);
    double v1 = (q - 1) / q, v2 = 1;
    int ans = 0;
    while(t - s > 0.000001)
    {
        double T = s / (v2 - v1);
//        printf("%f\n", T);
        if(t - T * v2 > 0.000001)
        {
//            printf("!%f\n", t - T * v2);
            ans++;
            s += v1 * T;
        }
        else
        {
            break;
        }
    }
    printf("%d\n", ans + 1);
    return  0;
}
