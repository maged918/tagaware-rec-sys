//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <numeric>
#include <functional> 

using namespace std;

//DEFINES BEGIN
#define OI(name) freopen(name, "r", stdin)
#define OO(name) freopen(name, "w", stdout)
#define OF(if_name, of_name) OI(if_name), OO(of_name)
#define faster ios_base::sync_with_stdio(false)
#define mp make_pair
#define mt make_tuple
#define sz(v) (int)v.size()
#define ALL(v) v.begin(), v.end()
#define MAKE_UPPER(str) transform(ALL(str), str.begin(), toupper)
#define MAKE_LOWER(str) transform(ALL(str), str.begin(), tolower)
#define randomize srand((unsigned int)time(0));
//DEFINES END

//POINT BEGIN
template<typename T>
struct POINT
{
	T x, y;
	POINT() {}
	POINT(T _x, T _y) : x(_x), y(_y) {}
	inline bool operator < (const POINT<T> &p)
	{
		return (x < p.x) || (x == p.x && y < p.y);
	}
};

template<typename T>
inline istream& operator >> (istream& is, POINT<T> &p)
{
	is >> p.x >> p.y;
	return is;
}

template<typename T>
inline ostream& operator << (ostream& os, POINT<T> &p)
{
	os << p.x << ' ' << p.y;
	return os;
}
//POINT END

//VECTOR BEGIN
template<typename T>
struct VECTOR
{
	T x, y;
	VECTOR() {}
	VECTOR(T _x, T _y) : x(_x), y(_y) {}
	inline const VECTOR<T>  operator - () const
	{
		return VECTOR<T>(-x, -y);
	}
	inline operator POINT<T>() const
	{
		return POINT<T>(x, y);
	}
};

template<typename T>
inline const VECTOR<T> operator + (const VECTOR<T> &v, const VECTOR<T> &u)
{
	return VECTOR<T>(v.x + u.x, v.y + u.y);
}

template<typename T>
inline const VECTOR<T> operator - (const VECTOR<T> &v, const VECTOR<T> &u)
{
	return VECTOR<T>(v.x - u.x, v.y - u.y);
}

template<typename T>
inline const VECTOR<T> operator * (const VECTOR<T> &v, T a)
{
	return VECTOR<T>(v.x * a, v.y * a);
}

template<typename T>
inline const VECTOR<T> operator / (const VECTOR<T> &v, T a)
{
	return VECTOR<T>(v.x / a, v.y / a);
}

template<typename T>
inline const VECTOR<T> operator * (T a, const VECTOR<T> &v)
{
	return VECTOR<T>(v.x * a, v.y * a);
}

template<typename T>
inline const VECTOR<T> operator / (T a, const VECTOR<T> &v)
{
	return VECTOR<T>(v.x / a, v.y / a);
}

template<typename T>
inline const POINT<T> operator + (const POINT<T> &p, const VECTOR<T> &v)
{
	return p + (POINT<T>)v;
}

template<typename T>
inline const POINT<T> operator - (const POINT<T> &p, const VECTOR<T> &v)
{
	return p - (POINT<T>)v;
}

template<typename T>
inline istream& operator >> (istream &is, VECTOR<T> &v)
{
	is >> v.x >> v.y;
	return is;
}

template<typename T>
inline ostream& operator << (ostream &os, VECTOR<T> &v)
{
	os << v.x << ' ' << v.y;
	return os;
}
//VECTOR END

//TYPEDEFS BEGIN
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll > pll;
typedef POINT<int> PINT;
typedef POINT<ll> PLL;
typedef POINT<db> PDB;
typedef POINT<ldb> PLDB;
typedef VECTOR<int> VINT;
typedef VECTOR<ll> VLL;
typedef VECTOR<db> VDB;
typedef VECTOR<ldb> VLDB;
//TYPEDEFS END

//CONSTANTS BEGIN
const ldb PI = acos(-1.0);
const ldb EPS = 1E-9;
const int MAXN = 100000 + 228;
const int INF = INT_MAX - 228;
const ll LLINF = LLONG_MAX - 228;
//CONSTANTS END

//GFUNCTIONS BEGIN
template<typename T>
inline const VECTOR<T> GET_VEC(POINT<T> a, POINT<T> b)
{
	return VECTOR<T>(b.x - a.x, b.y - a.y);
}

template<typename T>
inline T SCAL_PR(const VECTOR<T> &v, const VECTOR<T> &u)
{
	return v.x * u.x + v.y * u.y;
}

template<typename T>
inline T VEC_PR(const VECTOR<T> &v, const VECTOR<T> &u)
{
	return v.x * u.y - v.y * u.x;
}

template<typename T>
inline ldb LEN(const VECTOR<T> &v)
{
	return sqrt(SCAL_PR(v, v));
}

template<typename T>
inline T sqr(const T x)
{
	return x * x;
}
//GFUNCTIONS END

//INITIALIZATION BEGIN
ll n;
ll a[6];
//INITIALIZATION END

//FUNCTIONS BEGIN
//FUNCTIONS END
int main()
{
	//OF("input.txt", "output.txt");
	faster;
	randomize;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
	n = a[0] + a[1] + a[2];
	cout << sqr(n) - sqr(a[0]) - sqr(a[2]) - sqr(a[4]);
	EXIT: return 0;
}
