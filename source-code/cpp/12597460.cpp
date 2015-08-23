//Language: GNU C++11


#include <iostream>
#include <math.h>
#define EP 1e-6
using namespace std;

int main(void)
{
	int T, S, q, count = 1;
	// T : 노래의 전체 길이
	// S : 처음 다운로드 받는 길이
	// q : q초 경과하면 q-1초 만큼 다운로드 받음
	// count : 반복 재생 횟수

	cin >> T >> S >> q;

	double a = S;
	double r = double(q - 1) / q;
	double reach = a / (1 - r);

	while (floor(reach + EP) < T)
	{
		a = reach;
		reach = a / (1 - r);
		count++;
	}

	cout << count << endl;

	return 0;
}