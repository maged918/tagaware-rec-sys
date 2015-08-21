//Language: GNU C++


#include <iostream>
#include <cstdio>
using namespace std;

int num[6];

int main()
{
	while (cin >> num[0]) {
		for (int i = 1; i < 6; i++)
			cin >> num[i];
		int total = 0;
		int len = num[1] + num[2];
		int cur = num[0];
		int L = 0, R = 0;
		for (int i = 0; i < len; i++) {
			/* printf("%d ", cur); */
			if (L == 0 && R == 0) {
				total += cur*2 + 1;
				cur++;
			} else if (L == 1 && R == 1) {
				total += cur*2 - 1;
				cur--;
			} else {
				total += cur*2;
			}
			if (num[1] > 0)
				num[1]--;
			else
				num[2]--;
			if (num[1] == 0)
				R = 1;
			if (num[5] > 0)
				num[5]--;
			else
				num[4]--;
			if (num[5] == 0)
				L = 1;
		}
		/* printf("\n"); */
		printf("%d\n", total);
	}
	return 0;
}

  	 				 	 				  		   	     	