//Language: GNU C++


#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "queue"
using namespace std;
const int MAXN = 1e5 + 5;
int n, a[MAXN], b[MAXN];
queue<int> q;
int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		b[a[i]]++;
		if(b[a[i]] > 1 || a[i] > n) q.push(i);
	}
	for(int i = 1; i <= n; ++i) {
		if(!b[i]) {
			int x = q.front();
			a[x] = i;
			q.pop();
		}
		if(q.empty()) break;
	}
	for(int i = 0; i < n; ++i) 
		cout << a[i] << " ";
	cout << endl;
	return 0;
}