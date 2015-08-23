//Language: GNU C++


#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,a;
    while(~scanf("%d%d",&n,&a))
    {
        if(n==1 && a==1)
            printf("1\n");
        else
        {
            int l=a-1;;
            int r=n-a;
            if(l>=r)
                printf("%d\n",a-1);
            else if(l<r)
                printf("%d\n",a+1);
        }
    }
    return 0;
}

   	  			    			  	 	     	 			