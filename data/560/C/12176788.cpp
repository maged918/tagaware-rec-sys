//Language: GNU C++11


#include <cstdio>
#include <cmath>

using namespace std;

double x[6];
double area = 0, A, B, C, S;
const double sq3 = sqrt(3);

int main() {
	for(int i = 0; i < 6; ++i)
		scanf("%lf", x+i);

	area = ((x[0] * x[1] + x[2] * x[3] + x[4] * x[5]) /(double) 4) * sq3;
	A = sqrt(x[0] * x[0] + x[1] * x[1] - x[0] * x[1] * -1);
	B = sqrt(x[2] * x[2] + x[3] * x[3] - x[2] * x[3] * -1);
	C = sqrt(x[4] * x[4] + x[5] * x[5] - x[4] * x[5] * -1);
	S = (A+B+C)/(double)2;
	area += sqrt(S * (S - A) * (S - B) * (S - C));
	printf("%d", (int)round((area / sq3) * (double)4));
	return 0;
}
