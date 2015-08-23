//Language: GNU C++11


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define N 100020
#define INF 1000000007

#define C(x) memset(x, 0, sizeof(x))
#define go(i,n,m) for(int i=n; i<=m; i++)
#define run(i,n,m) for(int i=n; i<=m; i++)

using namespace std;

void gt(int &a, int b){ if (a < b) a = b; }
string n2s(int a){ stringstream ss; ss << a; return ss.str(); }
typedef pair<int,int> pi;
typedef long long ll;

set<int> s;
int n, a;

int cal(int l, int r){
    return (r-l)/(a+1);
}

int main() {
//            ifstream in;
//            in.open("/Users/Tom/Program/algo/programming_challenge/data/input.txt");
//            std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int k, m, x, lower, upper, count;
    cin >> n >> k >> a >> m;
    count = cal(0,n+1);
    s.insert(0);
    s.insert(n+1);
    go(i,1,m) {
        cin >> x;
        auto it = s.lower_bound(x);
        upper = *it;
        lower = *(--it);
        count = count - cal(lower, upper) + cal(lower, x) + cal(x, upper);
        if(count < k){
            cout << i << endl;
            return 0;
        }
        s.insert(x);
    }
    
    cout << "-1" << endl;
    return 0;
}