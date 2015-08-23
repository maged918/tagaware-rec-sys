//Language: MS C++


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

int city;
int num;
long long arr[100];

int answer[100];

int main(void)
{
	int i,j,max,winner,final;
   cin >> num >> city;
   
   for(i=0 ; i<num ; i++)
   {
      answer[i]=0;
   }
   for(j=0 ; j<city ; j++)
   {
      max=0;
      for(i=0 ; i<num ; i++)
      {
         scanf("%lld",&arr[i]);
      }

      for(i=num-1 ; i>=0 ; i--)
      {
         if(arr[i]>=max)
         {
            max=arr[i];
            winner=i;
         }
      }

      answer[winner]++;
   }
   max=0;
   for(i=num-1 ; i>=0 ; i--)
   {
      if(answer[i]>=max)
      {
         max=answer[i];
         final=i;
      }
   }

   cout << final+1 << endl;
   return 0;
}