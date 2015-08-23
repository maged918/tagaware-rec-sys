//Language: GNU C++


#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string s1,s2;

string smallest(string s)
{
    if (s.length() % 2 == 1) return s;
    string s1 = smallest(s.substr(0, s.length()/2));
    string s2 = smallest(s.substr(s.length()/2, s.length()));
    if (s1 < s2) return s1 + s2;
    else return s2 + s1;
}

int main()
{
	cin >> s1 >> s2;
	if(smallest(s1)==smallest(s2)) cout << "YES"; else cout << "NO";
	//getchar();getchar();
	return 0;
}
