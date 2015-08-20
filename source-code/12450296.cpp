//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

double T, S, q;
int cnt;
double x, y;

int main(void)
{
	while(3 == scanf("%lf %lf %lf", &T, &S, &q)){
		cnt = 0;
		double a = 0;		
		do{
			x = (S + a) * q;
			y = x - a;
			a = x;
			cnt++;
		}while(y < T);
		printf("%d\n", cnt);
	}
	return 0;
}