//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <iterator>
#include <limits>
#include <fstream>

#define F(i, b, a) for( int i = (b); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int arr [100005];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int size;
    scanf("%d", &size);
    F(i, 0, size){
        scanf("%d", &arr[i]);
    }
    printf("%d %d\n", arr[1] - arr[0], arr[size-1] - arr[0]);
    F(i, 1, size-1){
        printf("%d %d\n", min(arr[i] - arr[i-1], arr[i+1] - arr[i]), max(arr[i] - arr[0], arr[size-1] - arr[i]));
    }
    printf("%d %d\n", arr[size-1] - arr[size-2], arr[size-1] - arr[0]);
    //END

    return 0;
}
