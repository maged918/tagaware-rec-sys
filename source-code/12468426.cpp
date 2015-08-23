//Language: GNU C++


/*
* @author FreeWifi_novicer
* language : C++/C
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>

using namespace std;

#define clr( x , y ) memset(x,y,sizeof(x))
#define cls( x ) memset(x,0,sizeof(x))
#define mp make_pair
#define pb push_back
typedef long long lint;
typedef long long ll;
typedef long long LL;

const int mod = 1e9+7;
const int maxn = 4000 + 5;
lint B[maxn][maxn];
//lint C[maxn][maxn];

void init(){
    B[1][1] = 1;
    //cout << 1 <<endl;
    for(int i = 2 ; i <= 4001; i++){
        B[i][1] = B[i-1][i-1];
        //cout << B[i][1] << ' ';
        for(int j = 2 ; j <= i ; j++){
            B[i][j] = (B[i-1][j-1] + B[i][j-1]) % mod;
            //cout << B[i][j] <<' ';
        }
        //cout << endl;
    }
}
int main(){
//  freopen("input.txt","r",stdin);
    init();
    int n;
    while(cin >> n)
        cout << B[n+1][n] % mod << endl;
    return 0;
}
