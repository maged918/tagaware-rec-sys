//Language: GNU C++11


#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int mina, maxa; cin >> mina >> maxa;
    int minb, maxb; cin >> minb >> maxb;
    int minc, maxc; cin >> minc >> maxc;
    int diff = n - (mina + minb + minc);
    int ans1 = mina, ans2 = minb, ans3 = minc;
    if ((diff + mina) <= maxa)
	ans1 = mina + diff;
    else {
	ans1 = maxa;
	diff -= (maxa - mina);
	if ((diff + minb) <= maxb) ans2 = minb + diff;
	else {
	    ans2 = maxb;
	    diff -= (maxb - minb);
	    if ((diff + minc) <= maxc) ans3 = minc + diff;
	}
    }
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
}
