//Language: GNU C++11


/*
        By: facug91
        From: 
        Name: 
        Date: 22/07/2015
*/
 
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;      typedef vector<iii> viii;

int a[6];

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
    int i, j;

    for (i=0; i<6; i++) cin>>a[i];
    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            if (a[2]+a[4] <= a[0] && max(a[3], a[5]) <= a[1]) {
                cout<<"YES"<<endl;
                return 0;
            }
            if (max(a[2], a[4]) <= a[0] && a[3] + a[5] <= a[1]) {
                cout<<"YES"<<endl;
                return 0;
            }
            swap(a[4], a[5]);
        }
        swap(a[2], a[3]);
    }
    cout<<"NO"<<endl;
    
    
    
    
    
    
    
    
    
    return 0;
}