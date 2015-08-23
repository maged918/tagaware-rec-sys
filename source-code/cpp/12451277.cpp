//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <numeric>
#include <cassert>
#include <random>
#include <stdarg.h>
#include <string.h>
#include <stack>
#include <string>
#include <map>
#include <stdio.h>
#include <fstream>
#include <limits.h>
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>
#include <deque>
#include <queue>
#include <stdlib.h>
#include <unordered_set>


#include<bits/stdc++.h>
#define int long long int

using namespace std;

bool RANDOM = false;


#define DEBUG
#define NULL 0

#include <iostream>
#include <vector>
using namespace std;

double EPS = 0.0000000001;
double INF = 1000000000000000.0;


ostream_iterator<int> oi(cout, " ");

int minInt = 1;
int maxInt = 100;
double minDouble = -100000000000.0;
double maxDouble = 100000000000.0;


void setMaxInt(int newMax){
    maxInt = newMax;
}

void setMinInt(int newMin){
    minInt = newMin;
}

void setIntRange(int min, int max){
    maxInt = max;
    minInt = min;
}

void setMaxDouble(double newMax){
    maxDouble = newMax;
}

void setMinDouble(double newMin){
    minDouble = newMin;
}

void setDoubleRange(double min, double max){
    maxDouble = max;
    minDouble = min;
}

ostream & operator<<( ostream & out, pair<int, int>& c  )
{
    out << "<" <<c.first << ", ";
    out << c.second << ">" << endl;
    return out;
}

void print()
{
    std::cout << endl;
}



template<typename A>
void print(A value)
{
    std::cout << value;
}


template<>
void print<double>(double value)
{
    printf("%lf", value);
}

template<typename A, typename B>
void print(A value1, B value2)
{
    cout << value1 << " " << value2;
}

template<typename A, typename B, typename C>
void print(A value1, B value2, C value3)
{
    cout << value1 << " " << value2 << " " << value3;
}

template<typename A, typename B, typename C, typename D>
void print(A value1, B value2, C value3, D value4)
{
    cout << value1 << " " << value2 << " " << value3 << " " << value4;
}




template<typename A>
void println(A value)
{
    std::cout << value << endl;
}

template<typename A, typename B>
void println(A value1, B value2)
{
    cout << value1 << " " << value2 << endl;
}

template<typename A, typename B, typename C>
void println(A value1, B value2, C value3)
{
    cout << value1 << " " << value2 << " " << value3 << endl;
}

template<typename A, typename B, typename C, typename D>
void println(A value1, B value2, C value3, D value4)
{
    cout << value1 << " " << value2 << " " << value3 << " " << value4 << endl;
}

int randomint(int min, int max)
{
    return rand()%(max-min+1)+min;
}

double randomdouble(double min, double max)
{
    return (rand() / (double)RAND_MAX) * (max - min) + min;
}

template<typename E>
E read(){
    E value;
    cin >> value;
    return value;
}

template<>
int read<int>()
{
    if(!RANDOM) {
        int value;
        cin >> value;
        return value;
    } else {
        return randomint(minInt, maxInt);
    }
}

template<>
double read<double>()
{
    if(!RANDOM) {
        double value;
        cin >> value;
        return value;
    } else {
        return randomdouble(minDouble, maxDouble);
    }
}

/*
template<typename T>
Array<T> read<Array<T> >()
{
    int n = read<int>();
    Array<T> res(n);
    cin >> res;
    retrun res;
}
*/

istream& operator>>(istream& in, pair<int, int>& c)
{
    c.first = read<int>();
    c.second = read<int>();
    return in;
}

ostream& operator<<( ostream & out, string& c)
{
    for(int i = 0; i<c.length(); i++) {
        putchar(c[i]);
    }
    return out;
}

template<typename E>
class Array
{
public:
    int size;
    Array<E>(int _capacity) {
        capacity = _capacity;
        array = new E[capacity];
        size = capacity;
        fill();
    }

    void sort() {
        std::sort(&array[0], &array[size]);
    }


    Array() {
        capacity = 4;
        array = new E[capacity];
        size = 0;
    }

    Array(vector<E>& vect) {
        int _size = vect.size();
        capacity = _size*2;
        size = _size;
        array = new E[capacity];
        for(int i =0; i<size; i++) {
            array[i] = vect[i];
        }
    }

    Array(int minBound, int maxBound, int _size) {
        srand(_size);
        capacity = _size*2;
        size = _size;
        array = new E[capacity];
        for(int i = 0; i<size; i++) {
            array[i] = randomint(minBound, maxBound);
        }
    }

    void add(E item);
    int leftBinarySearch(E& item);
    int rightBinarySearch(E& item);
    pair<int, int> equalRange(E& item);
    bool binarySearch(E& item);
    void fill();
    E* begin();
    E* end();
    vector<E> toVector();
    void toString(ostream& stream);
    E& operator[](int i);
    E& index(int i);
    E* array;
private:
    int capacity;
    void ensureCapacity(int cap);
};


template <typename E>
void Array<E>::ensureCapacity(int cap)
{
    capacity = capacity*2;
    E* newArray = new E[capacity];
    memcpy(newArray, array, sizeof(E)*size);
    delete[] array;
    array = newArray;
}

template <typename E>
void Array<E>::fill()
{
    for(int i = 0; i<size; i++) {
        array[i] = NULL;
    }
}

template <>
void Array<pair<int, int> >::fill()
{
    for(int i = 0; i<size; i++) {
        array[i] = make_pair(0, 0);
    }
}

template <>
void Array<string>::fill()
{
    for(int i = 0; i<size; i++) {
        array[i] = "";
    }
}

template <typename E>
void Array<E>::toString(ostream& stream)
{
    int i = 0;
    while(i<size) {
        if(i == size-1) {
            stream << array[i];
        } else {
            stream << array[i] << " ";
        }
        i++;
    }
    stream << endl;
}

template <typename E>
void Array<E>::add(E item)
{
    if(capacity<size+1) {
        ensureCapacity(size+1);
    }
    array[size] = item;
    size++;
}

template <typename E>
E* Array<E>::begin()
{
    return array;
}

template <typename E>
E* Array<E>::end()
{
    return array + size;
}

template <typename E>
int Array<E>::leftBinarySearch(E& item)
{
    return lower_bound(array, array+size, item)-array;
}

template <typename E>
int Array<E>::rightBinarySearch(E& item)
{
    return upper_bound(array, array+size, item)-array;
}

template <typename E>
pair<int, int> Array<E>::equalRange(E& item)
{
    pair<int*, int*> p(0, 0);
    p = equal_range(array, array + size, item);
    return make_pair(p.first - array, p.second - array);
}

template <typename E>
bool Array<E>::binarySearch(E& item)
{
    return binary_search(array, array + size, item);
}

template <typename E>
vector<E> Array<E>::toVector()
{
    vector<E> res = vector<E>(size);
    for(int i =0; i<res.size(); i++) {
        res[i] = array[i];
    }
    return res;
}


template<typename T>
ostream & operator<<( ostream& out, Array<T>& c  )
{
    c.toString(out);
    return out;
}

ostream & operator<<( ostream & out, Array< pair<int, int> >& c  )
{
    for(int i = 0; i<c.size; i++) {
        out << c[i];
    }
    return out;
}

template<typename T>
istream& operator>>(istream& in, Array<T>& c  )
{
    for(int i = 0; i<c.size; i++) {
        c[i] = read<T>();
    }
    return in;
}


ostream& operator<<(ostream& out, map<int, int>& c  )
{
    map<int, int>::iterator it = c.begin();
    while(it!=c.end()) {
        pair<int, int> entry = *it;
        out << entry;
        it++;
    }
    return out;
}


Array<pair<int , int> > mapToArray(map<int, int>& c)
{
    Array<pair<int, int> > res(c.size());
    map<int, int>::iterator it = c.begin();
    int i = 0;
    while(it!=c.end()) {
        pair<int, int> entry = *it;
        res[i] = entry;
        i++;
        it++;
    }
    return res;
}

template <typename E>
E& Array<E>::operator[] (int i)
{
#ifdef DEBUG
    if(i<size && i>=0) {
        return array[i];
    } else {
        cout << "Array index out of bounds, index is " << i << ", size is " << size << endl;
        cout << "Array is " << endl;
        toString(cout);
        assert(0);
    }
#endif

#ifndef DEBUG
    return array[i]
#endif
}

template<typename E>
class Matrix
{
public:
    int rows;
    int columns;
    Array<E> array;

    E& get(int x, int y);
    void set(int x, int y, E& value);
    E& operator()(int x, int y);
    Matrix<E> transpose();

    pair<E*, E*> getRow(int y);

    Matrix<E>(int c, int r) {
        rows = r;
        columns = c;
        array = Array<E>(rows*columns);
        array.fill();
    }

    void swap(Matrix<E>& other) {
        std::swap(array, other.array);
        std::swap(rows, other.rows);
        std::swap(columns, other.columns);
    }

    Matrix<E>(int _columns, int _rows, int minBound, int maxBound) {
        rows = _rows;
        columns = _columns;
        int size = _rows*_columns;
        array = Array<E>(minBound, maxBound, size);
    }

private:
};

template<typename E>
Matrix<E> Matrix<E>::transpose()
{
    Matrix<int> b(rows, columns);
    for(int x = 0; x<columns; x++) {
        for(int y = 0; y<rows; y++) {
            b(y, x) = array.array[x+y*columns];
        }
    }
    return b;
}

template <typename E>
E& Matrix<E>::operator()(int x, int y)
{
#ifdef DEBUG
    if(x>=columns || x<0) {
        cout << "x must be in range [0; " << columns - 1 << "], but it is " << x << endl;
        assert(0);
    }
    if(y>=rows || y<0) {
        cout << "y must be in range [0; " << rows - 1 << "], but it is " << y << endl;
        assert(0);
    }
    return array.array[x+y*columns];
#endif
#ifndef DEBUG
    return array.array[x+y*columns];
#endif
}



template<typename T>
istream & operator>>(istream& in, Matrix<T>& c  )
{
    for(int y = 0; y<c.rows; y++) {
        for(int x = 0; x<c.columns; x++) {
            c(x, y) = read<T>();
        }
    }
    return in;
}


template<typename E>
pair<E*, E*> Matrix<E>::getRow(int y)
{
    E* f = array.array + y*columns;
    E* s = array.array + (y+1)*columns;
    pair<E*, E*> p(f, s);
    return p;
}


template<typename T>
ostream & operator<<( ostream & out, Matrix<T>& c  )
{
    for(size_t y = 0; y<c.rows; y++) {
        for(size_t x = 0; x<c.columns; x++) {
            out << c(x, y) << " ";
        }
        out << endl;
    }
	return out;
}


class Point
{
public:
    double x;
    double y;
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    Point() {
        x = 0;
        y = 0;
    }
};

double dist(Point& a, Point& b)
{
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

bool cmp(double a, double b)
{
    if(fabs(a-b) < EPS) {
        return true;
    } else {
        return false;
    }
}

class Triangle
{
public:
    Point A;
    Point B;
    Point C;

    double a;
    double b;
    double c;

    Triangle(Point _A, Point _B, Point _C) {
        A = _A;
        B = _B;
        C = _C;
        a = dist(C, B);
        b = dist(C, A);
        c = dist(A, B);
    }

    Triangle() {
    }

    double S() {
        return fabs((B.x - A.x)*(C.y - A.y)-(C.x-A.x)*(B.y-A.y));
    }
};

class Line
{
public:
    double A;
    double B;
    double C;

    double xmin;
    double xmax;

    Line(Point _A, Point _B, bool isSegment) {
        set(_A, _B, isSegment);
    }

    void set(Point _A, Point _B, bool isSegment) {
        if(isSegment) {
            xmin = min(_A.x, _B.x);
            xmax = max(_A.x, _B.x);
        } else {
            xmin = -INF;
            xmax = INF;
        }

        double k = (_B.y - _A.y)/(_B.x - _A.x);
        double b = _A.y - k*_A.x;

        //printf("%lf\n", b);

        A = k;
        B = -1.0;
        C = b;
    }

    void setSegment(Point _A, Point _B) {
        set(_A, _B, true);
    }

    void setLine(Point _A, Point _B) {
        set(_A, _B, false);
    }

    double getY(double x) {
        return A*x+C;
    }

    double length() {
        double x1 = xmin;
        double y1 = getY(xmin);
        double x2 = xmax;
        double y2 = getY(xmax);
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }

    int part(Point p) {
        if(fabs(A) > 100000000.0) {
            if(cmp(p.x, xmin)) {
                return 0;
            }

            if(p.x > xmin) {
                return 1;
            } else {
                return -1;
            }
        }

        if(cmp(A*p.x + B*p.y + C, 0.0)) {
            return 0;
        }

        if(A*p.x + B*p.y + C > 0) {
            return 1;
        }

        if(A*p.x + B*p.y + C < 0) {
            return -1;
        }
    }
};


istream& operator>>(istream& in, Point& c)
{
    c.x = read<int>();
    c.y = read<int>();
	return in;
}

ostream& operator<<(ostream& out, Point& c)
{
    out << "[" << c.x << ", " << c.y << "]" << endl;
	return out;
}


istream& operator>>(istream& in, Triangle& c)
{
    in >> c.A;
    in >> c.B;
    in >> c.C;
	return in;
}

ostream& operator<<(ostream& out, Triangle& c)
{
    out << c.A;
    out << c.B;
    out << c.C;
	return out;
}

istream& operator>>( istream& in, Line& c)
{
    Point a;
    Point b;
    in >> a;
    in >> b;
    c.setLine(a, b);
	return in;
}

ostream& operator<<( ostream& out, Line& c)
{
    cout << "y = " << c.A << "*x + " << c.C;
	return out;
}

int bpow(int a, int b)
{
    if(b == 0) {
        return 1;
    } else {
        if(b%2 == 0) {
            int half = bpow(a, b/2);
            return half*half;
        } else {
            return bpow(a, b-1)*a;
        }
    }
}

int fact(int n)
{
    if(n == 1) {
        return 1;
    } else {
        return n*fact(n-1);
    }
}

int gcd(int a, int b)
{
    if(!b) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

Array<pair<int, int> > factorize(int n, Array<int>& primeList)
{
    Array<pair<int, int> > res;
    for(int j = 0; j<primeList.size; j++) {
		int i = primeList[j];
        if(n%i == 0) {
            pair<int, int> comp = make_pair(i, 1);
            n/=i;
            while(n%i == 0) {
                comp.second++;
                n/=i;
            }
            res.add(comp);
        }
    }

    if(n>1) {
        res.add(make_pair(n, 1));
    }
    return res;
}

int euler(int n, Array<int>& primeList)
{
    Array<pair<int, int> > fact = factorize(n, primeList);
    int res = 1;
    for(unsigned int i = 0; i<fact.size; i++) {
        int factor = pow((double)fact[i].first, (double)fact[i].second)-pow((double)fact[i].first, (double)fact[i].second-1);
        res*=factor;
    }
    return res;
}

int inversePrime(int a, int m)
{
    return bpow(a, m-2)%m;
}

int inverseCoprimes(int a, int m, Array<int>& primeList)
{
    return bpow(a, euler(m, primeList)-1)%m;
}

int inverse(int a, int m, Array<int>& primeList)
{
    if(gcd(a, m) == 1) {
        return inverseCoprimes(a, m, primeList);
    } else {
        assert(0);
        return -1;
    }
}

Array<int> enumerateDivisors(int n, Array<int>& primeList)
{
    Array<pair<int, int> > divs = factorize(n, primeList);
    vector<int> totals = vector<int>(divs.size+1);
    totals[0] = 1;
    for(unsigned int i = 1; i < divs.size+1; i++) {
        totals[i]=totals[i-1]*(divs[i-1].second+1);
    }

    Array<int> res;
    for(int i = 0; i<totals[totals.size()-1]; i++) {
        vector<int> values = vector<int>(divs.size);
        for(unsigned int j = 0; j<values.size(); j++) {
            values[j] = (i/totals[j])%(divs[j].second+1);
        }
        int r = 1;
        for(unsigned int i = 0; i<values.size(); i++) {
            r*=bpow(divs[i].first, values[i]);
        }
        res.add(r);
    }
    return res;
}


void reverse(char *str)
{
    char temp;
    size_t len = strlen(str) - 1;
    size_t i;
    size_t k = len;

    for(i = 0; i < len; i++) {
        temp = str[k];
        str[k] = str[i];
        str[i] = temp;
        k--;
        if(k == (len / 2)) {
            break;
        }
    }
}

map<int, int> count(Array<int> a)
{
    map<int, int> res;
    for(int i = 0; i<a.size; i++) {
        res[a[i]]++;
    }
    return res;
}

void itoa(int n, char s[])
{
    int radix = 10;
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % radix + '0';
    } while ((n /= radix) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int* vectorToArray(vector<int> v)
{
    int* a = new int[v.size()];
    for(unsigned int i = 0; i<v.size(); i++) {
        a[i] = v[i];
    }
    return a;
}

char* stringToNumber(int number)
{
    char* res = new char[100];
    itoa(number, res);
    return res;
}

int numberToString(char* str)
{
    return atoi(str);
}


int booleanAnswerBinarySearch(Array<int> params, int left, int right, bool (*f)(Array<int> params, int v))
{
    if(f(params, left) && !f(params, left-1)) {
        return left;
    }

    if(f(params, right) && !f(params, right+1)) {
        return right;
    }

    int middle = (left+right)/2;
    int g = f(params, middle);
    if(g) {
        return booleanAnswerBinarySearch(params, left, middle, f);
    } else {
        return booleanAnswerBinarySearch(params, middle+1, right, f);
    }
}

Array< Array<int> > enumerarePermutations(int n)
{
    int fac = fact(n);
    Array<int> v;
    for(int i = 0; i<n; i++) {
        v.add(i+1);
    }
    Array< Array <int> > res;
    for(int i = 0; i<fac-1; i++) {
        Array<int> c(n);
        copy(v.array, v.array + v.size, c.array);
        res.add(c);
        next_permutation(v.array, v.array + v.size);
    }
    Array<int> c(n);
    copy(v.array, v.array + v.size, c.array);
    res.add(c);
    return res;
}

template <typename T>
Array< Array<T> > enumerarePermutations(Array<T>& array)
{
    int n = array.size;
    int fac = fact(n);
    Array<T> v;
    for(int i = 0; i<n; i++) {
        v.add(array[i]);
    }
    Array< Array <T> > res;
    for(int i = 0; i<fac-1; i++) {
        Array<T> c(n);
        copy(v.array, v.array + v.size, c.array);
        res.add(c);
        next_permutation(v.array, v.array + v.size);
    }
    Array<T> c(n);
    copy(v.array, v.array + v.size, c.array);
    res.add(c);
    return res;
}

Array< Array<int> > enumerareTuples(int n, int k)
{
    int q = bpow(k, n);
    Array< Array<int> > res(q);
    for(int i = 0; i<q; i++) {
        Array<int> tuple(n);
        for(int j = 0; j<n; j++) {
            tuple[j] = (i/bpow(k, j))%k;
        }
        res[i] = tuple;
    }
    return res;
}

template <typename T>
Array< Array<int> > enumerareTuples(int n, Array<T> array)
{
    int k = array.size;
    int q = bpow(k, n);
    Array< Array<T> > res(q);
    for(int i = 0; i<q; i++) {
        Array<int> tuple(n);
        for(int j = 0; j<n; j++) {
            tuple[j] = array[(i/bpow(k, j))%k];
        }
        res[i] = tuple;
    }
    return res;
}

bool* sieve(int bound)
{
    bool* array = new bool[bound+1]();
    for(int i = 2; i*i<=bound; i++) {
        if(!array[i]) {
            for(int j = i+i; j<=bound; j+=i) {
                array[j] = 1;
            }
        }
    }
    return array;
}

Array<int> sieveList(int bound)
{
    bool* array = new bool[bound+1]();
    for(int i = 2; i*i<=bound; i++) {
        if(!array[i]) {
            for(int j = i+i; j<=bound; j+=i) {
                array[j] = 1;
            }
        }
    }
	
	Array<int> a;
	for(int i = 2; i<bound+1; i++){
		if(!array[i]){
			a.add(i);
		}
	}
	
    return a;
}

int f(int k)
{
    return k&(k+1);
}

string alignLeft(string a, int length, char ch)
{
    if(a.length() < length) {
        a = string(length - a.length(), ch) + a;
    }
    return a;
}

string decToRadix(int n, int radix)
{
    string res("");
    if(n == 0) {
        res.push_back('0');
        return res;
    }
    while(n) {
        int digit = n%radix;
        res.push_back((char)(digit + '0'));
        n/=radix;
    }
    reverse(res.begin(), res.end());
    return res;
}

int radixToDec(string s, int radix)
{
    int res = 0;
    reverse(s.begin(), s.end());
    for(int i = 0; i<s.length(); i++) {
        res+=(s[i]-'0')*bpow(radix, i);
    }
    return res;
}

class F
{
public:
    int (*f)(int, int);
    int (*inverse)(int, int);
    int NEUTRAL;

    F(int(*pf)(int, int), int (*pinverse)(int, int), int n) {
        f = pf;
        inverse = pinverse;
        NEUTRAL = n;
    }

    F() {
    }

    int operator()(int a, int b) {
        return f(a, b);
    }

    int inversed(int a, int b) {
        return inverse(a, b);
    }
};


class BIT
{
public:
    F f;
    Array<int> tree;
    Array<int> array;

    BIT(F func, Array<int> source) {
        Array<int> arr(source.size);
        copy(source.begin(), source.end(), arr.begin());
        array = arr;
        f = func;

        Array<int> tr(source.size);
        tree = tr;

        for(int i = 0; i<source.size; i++) {
            add(i, array[i]);
        }
    }

    void add(int i, int delta) {
        for(int u = i; u<tree.size; u = u | (u+1)) {
            tree[u]=f(tree[u], delta);
        }
    }

    int value(int l, int r) {
        return f.inversed(p(r), p(l - 1));
    }

    int p(int v) {
        if(v < 0) {
            return 0;
        }
        if(v == 0) {
            return tree[0];
        } else {
            return f(tree[v], p((v&(v+1)) - 1));
        }
    }
};



class Graph{
public:
    int n = 0;
    int m = 0;
    vector<vector<int> > adj;
    vector<vector<int> > w;
    bool isDirected = false;
    bool isWeighted = false;

    Graph(){
    }

    void setDirected(){
        this->isDirected = true;
    }

    void setWeighted(){
        this->isWeighted = true;
    }

    Graph(int n){
        this->n = n;
        vector<vector<int> > _adj(2*n+1);
        vector<vector<int> > _w(2*n+1);
        adj = _adj;
        w = _w;
    }

    void readByMatrix(){
        bool last = this->isDirected;
        this->isDirected = true;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int x;
                cin >> x;
                if(this->isWeighted){
                    if(x != -1){
                        this->addWeighted(i, j, x);
                    }
                }
                else{
                    if(x != 0){
                        this->add(i, j);
                    }
                }
            }
        }
        this->isDirected = last;
    }

    void printWeights(){
        for(int i = 0; i<n; i++){
            cout << i << " {";
            for(int j = 0; j<w[i].size(); j++){
                if(j!=adj[i].size()-1){
                    cout << w[i][j] << " ";
                }
                else{
                    cout << w[i][j];
                }
            }
            cout << "}";
            cout << endl;
        }
    }

    void add(int a, int b){
        this->m++;
        adj[a].push_back(b);
        if(!this->isDirected){
            this->m++;
            adj[b].push_back(a);
        }
    }

    void addWeighted(int a, int b, int weight){
        this->m++;
        adj[a].push_back(b);
        w[a].push_back(weight);
        if(!this->isDirected){
            this->m++;
            adj[b].push_back(a);
            w[b].push_back(weight);
        }
    }

    void dfs(int v, int* p, vector<int>& graypath, Array<int>& cycles, Array<int>& res, Array<int>& outs, int* color){
        color[v] = 1;
        res.add(v);
        graypath.push_back(v);
        for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i];
            if(color[u] == 0){
                p[u] = v;
                dfs(u, p, graypath, cycles, res, outs, color);
            }

            if(color[u] == 1){
                if(p[v]!=u){
                    Array<int> cycle;
                    bool now = false;
                    for(int i = 0; i<graypath.size(); i++){
                        if(graypath[i] == u){
                            now = true;
                        }

                        if(now){
                            cycle.add(graypath[i]);
                        }

                        if(graypath[i] == v){
                            now = false;
                        }
                    }
                    cycles = cycle;
                }
            }
        }
        graypath.pop_back();
        color[v] = 2;
        outs.add(v);
    }

    Array<int> dfs(int number){
        int* color = new int[n]();
        int* p = new int[n]();
        Array<int> res;
        Array<int> outs;
        Array<int> cycles;
        vector<int> path;
        dfs(number, p, path, cycles, res, outs, color);
        return res;
    }

    Array<Array<int> > findConnectedComponents(){
        Array<Array<int> > res;
        int* array = new int[n]();
        for(int i = 0; i<n; i++){
            if(!array[i]){
                Array<int> component = dfs(i);
                for(int j = 0; j<component.size; j++){
                    array[component[j]] = i+1;
                }
                res.add(component);
            }
        }
        return res;
    }

    void shortestPath(Array<int>& p, int from, int to, Array<int>& res){
        if(from == to){
            res.add(from);
        }
        else{
            res.add(to);
            int newTo = p[to];
            shortestPath(p, from, newTo, res);
        }
    }

    Array<int> shortestPath(Array<int>& p, int from, int to){
        Array<int> res;
        shortestPath(p, from, to, res);
        reverse(res.begin(), res.end());
        return res;
    }

    Array<int> bfsPath(int s, int t){
        Array<int> p(n);
        Array<int> dists(n);
        bfs(p, dists, s);
        for(int i = 0; i<n; i++){
            dists[i] = -1;
        }
        return shortestPath(p, s, t);
    }

    Array<int> bfsDists(int root){
        Array<int> p(n);
        Array<int> dists(n);
        for(int i = 0; i<n; i++){
            dists[i] = -1;
        }
        bfs(p, dists, root);
        return dists;
    }

    Array<int> findCycles(){
        int* color = new int[n]();
        int* p = new int[n]();
        Array<int> res;
        Array<int> outs;
        Array<int> cycles;
        vector<int> graypath;
        dfs(0, p, graypath, cycles, res, outs, color);
        return cycles;
    }

    void bfs(Array<int>& p, Array<int>& dists, int root){
        queue<int> q;
        q.push(root);
        int* visited = new int[this->n]();
        visited[root] = true;
        dists[root] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int i = 0; i<adj[v].size(); i++){
                int u = adj[v][i];
                if(!visited[u]){
                    visited[u] = true;
                    dists[u] = dists[v]+1;
                    p[u] = v;
                    q.push(u);
                }
            }
        }
    }

    Array<int> toposort(){
        n++;
        vector<int> newAdj;
        adj[n] = newAdj;
        for(int i = 0; i<n-1; i++){
           this->add(n-1, i);
        }
        Array<int> res;
        Array<int> outs;
        vector<int> path;
        Array<int> cycles;
        int* color = new int[n]();
        int* pr = new int[n]();
        dfs(n-1, pr, path, cycles, res, outs, color);
        n--;

        Array<int> p(outs.size - 1);
        for(int i = 0; i<outs.size - 1; i++){
            p[i] = outs[i];
        }
        reverse(p.begin(), p.end());

        Array<int> r(p.size);
        for(int i = 0; i<p.size; i++){
            r[p[i]] = i;
        }

        for(int i = 0; i<n; i++){
             for(int j = 0; j<adj[i].size(); j++){
                 int v = adj[i][j];
                 if(r[i]>=r[v]){
                     Array<int> sh(0);
                     return sh;
                 }
             }
        }

        return p;
    }

    int INF = 1000000000;
    int INFP = 1000000000/2;


    
    void Dijkstra(Array<int>& p, Array<int>& dists, int root){
        for(int i = 0; i<n; i++){
            dists.add(this->INF);
        }
        dists[root] = 0;

        for(int i = 0; i<n; i++){
            p.add(this->INF);
        }
        p[root] = root;


        int* used = new int[n]();
        int v = root;
        for(int i = 0; i<n; i++){
            used[v] = true;
            for(int j = 0; j<adj[v].size(); j++){
                int u = adj[v][j];
                if(used[u] == false){
                    int newD = dists[v]+w[v][j];
                    if(newD < dists[u]){
                        p[u] = v;
                        dists[u] = newD;
                    }
                }
            }

            int newV = -1;
            int minDist = this->INF+this->INF;
            for(int i = 0; i<n; i++){
                if(!used[i]){
                    if(dists[i] < minDist){
                        newV = i;
                        minDist = dists[i];
                    }
                }
            }

            v = newV;
        }
    }
    

	/*
    void Dijkstra(Array<int>& p, Array<int>& d, int s){
        for(int i = 0; i<n; i++){
            d.add(this->INF);
        }
        d[s] = 0;

        for(int i = 0; i<n; i++){
            p.add(this->INF);
        }
        p[s] = s;

        set < pair<int,int> > q;
        q.insert (make_pair (d[s], s));
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase (q.begin());
            for (size_t j=0; j<adj[v].size(); ++j) {
                int to = adj[v][j];
                int len = w[v][j];
                if (d[v] + len < d[to]) {
                    q.erase (make_pair (d[to], to));
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.insert (make_pair (d[to], to));
                }
            }
        }
    }
	 * */
};

int clp2(int x) { 
	x--;
	for (int p=1; p<32; p<<=1) x |= (x >> p);
	return ++x;
}

void fillArray(Array<int>& a){
	int need = clp2(a.size);
	for(int i = a.size; i<need; i++){
		a.add(0);
	}
}

int sumOfDigits(int n){
	int res = 0;
	for(int x = n; x; x/=10){
		res += x%10;
	}
	return res;
}

int numOfDigits(int n){
	int res = 0;
	for(int x = n; x; x/=10){
		res++;
	}
	return res;
}

istream& operator>>(istream& in, Graph& g)
{
    int n;
    int m;
    cin >> n >> m;
    Graph graph(n);
    graph.isDirected = g.isDirected;
    graph.isWeighted = g.isWeighted;
    for(int i = 0; i<m; i++){
        int x;
        int y;
        cin >> x >> y;
        if(!graph.isWeighted){
            graph.add(x-1, y-1);
        }
        else{
            int w;
            cin >> w;
            graph.addWeighted(x-1, y-1, w);
        }
    }
    g = graph;
    return in;
}

ostream& operator<<(ostream& out, Graph& g)
{
    for(int i = 0; i<g.n; i++){
        out << i << " {";
        for(int j = 0; j<g.adj[i].size(); j++){
            if(j!=g.adj[i].size()-1){
                out << g.adj[i][j] << " ";
            }
            else{
                out << g.adj[i][j];
            }
        }
        out << "}";
        out << endl;
    }
    return out;
}


int pot(int x){
	return !(x&(x-1));
}


bool isPol(int a){
	if(a == 0){
		return false;
	}
	char* s = new char[10];
	itoa(a, s);
	int len = strlen(s);
	for(int i = 0; i<len/2; i++){
		if(s[i] != s[len - i - 1]){
			return false;
		}
	}
	return true;
}


#undef int
int main(void)
{
#define int long long int
RANDOM = 0;
srand (time(NULL));
cout.precision(20);
//freopen("enchanted.in", "r", stdin);
//freopen("enchanted.out", "w", stdout);
std::ios::sync_with_stdio(false);
		
		
	int p, q;
	cin >> p >> q;
	
	int bound = 6000000;
	bool* primes = sieve(bound);
	
	int* summsPrimes = new int[bound]();
	int* summsPol = new int[bound]();
	for(int i = 1; i<bound; i++){
		if(!primes[i] && i>=2){
			summsPrimes[i] = summsPrimes[i-1]+1;
		}
		else{
			summsPrimes[i] = summsPrimes[i-1];
		}
		
		if(isPol(i)){
			summsPol[i] = summsPol[i-1]+1;
		}
		else{
			summsPol[i] = summsPol[i-1];
		}
	}
	
	int res = 0;
	int max = 0;
	
	int MAX_MAX = 1000000;
	
	for(int i = 0; i<bound; i++){
		bool f = q*summsPrimes[i] <= p * summsPol[i];
		//cout << i << " " << summsPrimes[i] << " " << summsPol[i] << " " << f <<  endl;
		
		if(f){
			res = i;
		}
		else{
			max++;
		}
	}
	
	if(max > MAX_MAX){
		cout << res << " ";
	}
	else{
		cout << "Palindromic tree is better than splay tree";
	}
}

