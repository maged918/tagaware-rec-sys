//Language: MS C++


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main(void)
{
	int a,b,c,d,e,f,ans=0;
	cin >> a >> b >> c >> d >> e >> f;
	if((a>=c+e && b>=d && b>=f) || (b>=c+e && a>=d && a>=f))
		ans=1;
	if((a>=c+f && b>=d && b>=e) || (b>=c+f && a>=d && a>=e))
		ans=1;
	if((a>=d+e && b>=c && b>=f) || (b>=d+e && a>=c && a>=f))
		ans=1;
	if((a>=d+f && b>=c && b>=e) || (b>=d+f && a>=c && a>=e)) 
		ans=1;
	if(ans==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}