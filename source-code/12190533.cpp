//Language: GNU C++11


#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

bool isEquivalent(int inc1, int sf1, int inc2, int sf2);
bool equal(int inc1, int sf1, int inc2, int sf2);

char s1[200010], s2[200010];

int main() {
	int i;

	scanf("%s\n%s", &s1, &s2);

	int len = strlen(s1) - 1;
	if (isEquivalent(0, len, 0, len))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

bool equal(int inc1, int sf1, int inc2, int sf2) {
	for (int i = 0; i <= (sf1 - inc1); ++i)
		if (s1[inc1 + i] != s2[inc2 + i])
			return false;

	return true;
}

bool isEquivalent(int inc1, int sf1, int inc2, int sf2) {
	if (equal(inc1, sf1, inc2, sf2))
		return true;
	else {
		if ((sf1 - inc1 + 1) & 1)
			return false;

		int i;

		int m1 = (sf1 + inc1 + 1) / 2;
		int m2 = (sf2 + inc2 + 1) / 2;
		if (isEquivalent(inc1, m1 - 1, inc2, m2 - 1) && isEquivalent(m1, sf1, m2, sf2) || isEquivalent(inc1, m1 - 1, m2, sf2) && isEquivalent(m1, sf1, inc2, m2 - 1))
			return true;
		else
			return false;
	}
}
