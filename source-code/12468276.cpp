//Language: MS C++


#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include  <climits>
#include   <cstring>
#include <list>
#include  <iomanip>

#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index = 0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int index = from + 1; index  < vec.size(); ++index)


set<int> GetPrimes(int n)
{
	set<int> res;
	vector<bool> s(n, false);
	s[0] = true;
	s[1] = true;
	//res.insert(1);
	F2(i, s)
	{
		if (!s[i])
		{
			for (int j = i; j < s.size();  j += i)
			{
				s[j] = true;
			}
			res.insert(i);
		}
	}
	return res;
}

int const MAX = 2000000;
set<int> primes = GetPrimes(MAX);

bool IsPrime(int n)
{
	return primes.count(n) == 1;
}

stringstream stream;
bool IsPal(int n)
{
	stream << n;
	string str = stream.str();
	stream.str("");
	stream.clear();
	
	for (int i = 0; i < str.size() / 2; ++i)
	{
		if (str[i] != str[str.size() - 1 - i]) return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	int q, p;
	cin >> p >> q;

	int pal = 0;
	int prime = 0;
	int res = 0;
	for (int i = 1; i < MAX; ++i)
	{
		if (IsPal(i)) pal++;
		if (IsPrime(i)) prime++;

		
		if (q * prime <= p * pal)
		{
			res = i;
		}
		
	}
	cout << res << endl;
	return 0;
}