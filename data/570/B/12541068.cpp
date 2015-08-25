//Language: GNU C++


#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n == 1)cout<<1<<endl;
    else if(n % 2)
    {
        int mid = (n+1)/2;
        if(m >= mid)cout<<m-1<<endl;
        else cout<<m+1<<endl;
    }
    else
    {
        int mm = n / 2;
        if(m <=mm)cout<<m+1<<endl;
        else cout<<m-1<<endl;
    }
    return 0;
}

	  			    				    	 		 	 		  		