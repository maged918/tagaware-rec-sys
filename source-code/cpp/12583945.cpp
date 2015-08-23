//Language: GNU C++


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, s;
    double q;
    scanf("%d%d%lf", &t, &s, &q);
    int i = 0;
    while(s < t){
        ++i;
        s *= q;
    }
    printf("%d\n", i);
    return 0;
}

  	 		 	 		    	 			 	   		  		