//Language: MS C++


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define forn(i,n) for(int i =0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<=b;i++)

bool check(string a, string b)
{
	if (a == b)return true;
	int q = a.length();
	if ((q % 2) == 1) return false;
	return (check(a.substr(0, q / 2), b.substr(q / 2, q / 2)) && check(b.substr(0, q / 2), a.substr(q / 2, q / 2))) || (check(a.substr(0, q / 2), b.substr(0, q / 2)) && check(b.substr(q/2, q / 2), a.substr(q / 2, q / 2)));
}

int main()
{
	string a, b;
	cin >> a >> b;
	if (check(a, b))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}