//Language: GNU C++11


#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stack>
#include <limits.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define SZ(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define LLI long long int
using namespace std;
double PI = 3.1415926536;
int dX[] = { 1, -1, 0, 0 };
int dY[] = { 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n ,mx = 0, co = 0;
    cin >> n;
    map<int, int>mp1;
    vector<pair<char, int> > v(n);
    FOR(i, 0, n)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].first == '+')
            co++, mp1[v[i].second] = 1;
        else if (v[i].first == '-')
        {
            if (!mp1[v[i].second])
                mx++;
            else
                co--;
        }
        mx = max(mx, co);
    }
    cout << mx;
}