//Language: GNU C++


#include <algorithm>
#include <iostream>

#define For(a,b,c) for(int a=b;a < c;a++)
#define PII pair < int,int > 
#define X first
#define C second

using namespace std;

int n;

PII tree[2][1001];

int move(int x,int dir,int fake){
	if(x == -1 || x == n){   return 0;   }
	if(tree[fake][x].C == 0){   x += dir;   return move(x,dir,fake);   }
	dir *= -1;
	int y = tree[fake][x].C;
	tree[fake][x].C = 0;
	x += dir;
	return move(x,dir,fake) + y;
}

int main(){
	cin >> n; 
	int ans = 0,begin = 0;
	For(i,0,n){   cin >> tree[0][i].X >> tree[0][i].C;  if(tree[0][i].X == 0){   ans += tree[0][i].C;   tree[0][i].C = 0;   }   tree[1][i] = tree[0][i];    }
	tree[0][n].X = tree[0][n].C = 0 ;
	tree[1][n] = tree[0][n];
	n++;
	sort(tree[0],tree[0] + n);
	sort(tree[1],tree[1] + n);
	for(;tree[0][begin].X < 0;begin++);
	ans += max( move(begin,1,0),move(begin,-1,1) );
	cout << ans << "\n";
}