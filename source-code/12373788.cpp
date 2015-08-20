//Language: GNU C++


#include <cstdlib> 
#include <cstring> 
#include <iostream>
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector>
#include <string>
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <list> 
#include <climits>

using namespace std;

int n, k, a;
int m;
int x[300000];
int tmp_x[300000];

int cmp (const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

bool check (int pos) {
	//printf ("pos: %d\n", pos);
	
	memcpy (tmp_x, x, sizeof(int) * (pos + 1));
	qsort (tmp_x, pos + 1, sizeof(int), cmp);
	tmp_x[pos + 1] = n + 1;
	pos++;
	
	int cnt = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i <= pos; i++) {
		left = right;
		right = tmp_x[i];
		//printf ("left: %d, right %d\n", left, right);
		
		int size = right - left;
		cnt += size / (a + 1);
		if (cnt >= k) {
			//printf ("true\n");
			return true;
		}
	}
	return false;
}

int main() {
	scanf ("%d%d%d", &n, &k, &a);
	scanf ("%d", &m);	

	for (int i = 0; i < m; i++)
		scanf ("%d", &x[i]);
	x[m] = n + 1;
	m++;
	
	int left_pos = 0;
	int right_pos = m - 1;
	
	for ( ; ; ) {
		//printf ("L: %d, R: %d\n", left_pos, right_pos);
		if (left_pos == right_pos)
			break;
		
		int mid = (left_pos + right_pos) / 2;
		if (check(mid))
			left_pos = mid + 1;
		else
			right_pos = mid;
	}
	if (left_pos != m - 1)
		printf ("%d\n", left_pos + 1);
	else
		printf ("-1\n");
	
	return 0;		
}
	