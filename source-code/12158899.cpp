//Language: GNU C++


#include<cstdio>
#include<string.h>
#include<math.h>
#include<iostream>

using namespace std;
int upzero[100007];
int downzero[100007];
int main()
{
    int TotalL=0,TotalR=0;
    int n;
    scanf("%d",&n);
    int situation,apple;
    int sumApple=0;
    int MaxSitL=0,MaxSitR=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&situation,&apple);
        if(situation>0)
        {
            upzero[situation]=apple;
            sumApple+=apple;
            TotalR++;
            if(situation>MaxSitR)
                MaxSitR=situation;
        }
        else
        {
            situation=(int)fabs(situation);
            downzero[situation]=apple;
            sumApple+=apple;
            TotalL++;
            if(situation>MaxSitL)
                MaxSitL=situation;
        }
    }
    int abs=TotalL-TotalR;
    if(abs<0)
    {
        abs++;
        for(int i=MaxSitR;i>0;i--)
        {
            if(abs==0)
            {
                break;
            }
            if(upzero[i]!=0)
            {
                sumApple-=upzero[i];
                abs++;
            }
        }
    }
    else if(abs>0)
    {
        abs--;
        for(int i=MaxSitL;i>0;i--)
        {
            if(abs==0)
            {
                break;
            }
            if(downzero[i]!=0)
            {
                sumApple-=downzero[i];
                abs--;
            }
        }
    }
    printf("%d\n",sumApple);
    return 0;
}

 	   		 	 	    	 	 						   	 	