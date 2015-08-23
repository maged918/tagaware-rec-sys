//Language: GNU C++11


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename Iterator>
inline bool same_string(Iterator a, Iterator b, size_t len) {
	bool same = true;
	for (int i = 0; i < len; i++) {
		if (*(a+i) != *(b+i)) {same = false; break; }
	}
	return same;
}

template <typename Iterator>
bool is_the_same(Iterator a, Iterator b, size_t len) {
	if (same_string(a, b, len)) {return true;}
	if (len & 0x01) return false;
	len >>= 1;
	return (is_the_same(a, b, len) && is_the_same(a + len, b+len, len) ) || (is_the_same(a, b+len, len) && is_the_same(a + len, b, len));
}

int main() {
	std::string a, b;
	cin >> a >> b;
	bool same = is_the_same(a.begin(), b.begin(), a.size());
	cout << (same ? "YES" : "NO");
	return 0;
}
