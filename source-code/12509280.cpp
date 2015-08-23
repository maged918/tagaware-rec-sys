//Language: GNU C++


#include <iostream>
#include <cstdio>
using namespace std;

string a;
int n, m, s, num;
bool b[300005];
char c;
int main()
{
	int i;
//	freopen ("input.txt", "r", stdin);
	cin >> n >> m;
	cin >> a;
	for (i = 0; i < n - 1; i++) {
		if (a[i] == '.' && a[i + 1] == '.') {
			b[i] = true;
			s++;
		}
	}

	for (i = 0; i < m; i++) {
		scanf ("%d %c", &num, &c);
		num--;
		if (a[num] != '.' && c == '.') {
			if (num >= 1 && a[num - 1] == '.' && !b[num - 1]) {
				b[num - 1] = true;
				s++;
			}
			if (a[num + 1] == '.' && !b[num]) {
				b[num] = true;
				s++;
			}
		}
		if (a[num] == '.' && c != '.') {
			if (num >= 1 && a[num - 1] == '.' && b[num - 1]) {
				b[num - 1] = false;
				s--;
			}
			if (b[num]) {
				b[num] = false;
				s--;
			}
		}
		a[num] = c;
		printf("%d\n", s);
	}
    return 0;
}
