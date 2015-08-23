//Language: GNU C++


#include <iostream>
#include <algorithm>
#include<map>
#include<string>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>
#include<utility>
#include<math.h>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,x,y) for(int i=x; i<=y; i++)
#define Min(a,b) a<b?a:b
#define PI 3.14159265

float shoelace(int n, float a[100][2])
{
	//area of polygon
	float area=0.0;
	REP(i,n-1)
	{
		area=area+a[i][0]*a[i+1][1];
		area=area-(a[i+1][0]*a[i][1]);
	}
	area=area+a[n-1][0]*a[0][1]-a[0][0]*a[n-1][1];
	area=area/2.0;
	if(area<0)
			area=area*-1;
	return area;	

}
int main()
{
	int n=6;
	float a[6][2];
	int b[6],ct=0;
	int min=0;
	REP(i,n)
	{
		cin>>b[i];
	}

	a[0][0]=0,a[0][1]=0;
	a[1][0]=b[3],a[1][1]=0;
	a[2][0]=b[3]+0.5*b[2],a[2][1]=b[2]*sin(60.0*PI/180.0);
	a[3][0]=a[2][0]-0.5*b[1],a[3][1]=a[2][1]+b[1]*sin(60.0*PI/180.0);
	a[4][0]=a[3][0]-b[0],a[4][1]=a[3][1];
	a[5][0]=a[4][0]-0.5*b[5],a[5][1]=a[4][1]-sin(60.0*PI/180.0)*b[5];


	float area=shoelace(6,a);

	float eq=0.5*cos(30.0*PI/180.0);
	int ans=round(area/eq);
	cout<<ans<<"\n";



	return 0;
}
