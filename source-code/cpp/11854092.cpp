//Language: GNU C++


#include<iostream>
#define __STDC_FORMAT_MACROS
#include<stdio.h>
#include<inttypes.h>
int main()
{   int64_t n,min1,min2,min3,max1,max2,max3,first,second,third;
    scanf("%"PRId64,&n);
    scanf("%"PRId64"%"PRId64 ,&min1,&max1);
    scanf("%"PRId64"%"PRId64 ,&min2,&max2);
    scanf("%"PRId64"%"PRId64 ,&min3,&max3);
    third=min3;
    n=n-min3;
    second=min2;
    n=n-min2;
    if(n>=min1 && n<=max1)
    first=n;
    else if(n>max1)
    {   first=max1;
        n=n-max1;
        if(n+second<=max2)
        {   second=second+n;
        }else
        {   second=max2;
            n=n-max2+min2;
            third=third+n;
        }
    }
    printf("%"PRId64" %"PRId64" %"PRId64"\n",first,second,third);
    return 0;
}