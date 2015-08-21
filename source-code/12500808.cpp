//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;

#define rep(i,a,b) for (int i =a ; i < b; ++i)

int main(){
  int n, m; cin >> n >> m;
  vvi votes(m,vi(n,0));
  rep(i,0,m){
    rep(j,0,n){
      cin >> votes[i][j];
    }
  }
  vi cities(n,0);
  rep(i,0,m){
    int index = 0;
    int total1 = 0;
    rep(j,0,n){
      if (votes[i][j] > total1){
        index = j;
        total1 = votes[i][j];
      } 
    }
    cities[index]++;
  }
  int index = 0;
  int total = 0;
  rep(i,0,n) if (cities[i] > total){
    total = cities[i];
    index = i;
  }
  cout << index + 1<< endl;
}
