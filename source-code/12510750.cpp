//Language: GNU C++11


#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

//macros
typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;




#define FOR(k,a,b) for(int k=(a); k<=(b); ++k)
#define REP(k,a) for(int k=0; k<(a);++k)
#define SZ(a) int((a).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define INF 99999999
#define MOD 1000000007

int main() {
	int n,queries;
	cin >> n >> queries;
	string str;
	cin >> str;
	str = "X" + str;
	str = str + "X";
	if(n==1){
		REP(i,queries){
			cout << 0 << endl;
		}
		return 0;
	}
	int groups=0;
	int adj=0;
	int left = 1;
	int right = n;
	for(int ind=1; ind < str.length(); ind++){
		if(str[ind]!='.' && str[ind-1]=='.'){
			groups++;
		}
		if(str[ind]=='.') adj++;
	}
	//cout << groups << " " << adj << endl;
	REP(i,queries){
		//cout << groups << " " << adj << endl;
		int pos;
		char c;
		cin >> pos >> c;


		bool hasleft=false,hasright=false;
		if(pos!=left) hasleft = true;
		if(pos!=right) hasright = true;
		//cout <<"YO " << i << " " << hasleft << " " << hasright << endl;
		char prevc = str[pos];
		if(prevc=='.'){
			if(c=='.'){

			}
			else{
				if(hasleft && hasright && str[pos-1]!='.' && str[pos+1]!='.'){
					groups--;
					adj--;
				}
				else if(hasleft && hasright && str[pos-1]=='.' && str[pos+1]!='.'){
					adj--;
				}
				else if(hasleft && hasright && str[pos-1]!='.' && str[pos+1]=='.'){
					adj--;
				}
				else if(hasleft && hasright && str[pos-1]=='.' && str[pos+1]=='.'){
					adj--;
					groups++;
				}
				else if((hasleft && str[pos-1]=='.') || (hasright && str[pos+1]=='.')){
					adj--;
				}
				else if((hasleft && str[pos-1]!='.') || (hasright && str[pos+1]!='.')){
					adj--;
					groups--;
				}
			}
		}
		else if(prevc!='.'){
			if(c=='.'){
				if(hasleft && hasright){
					if(str[pos-1]=='.' && str[pos+1]=='.'){
						groups--;
						adj++;
					}
					else if((str[pos-1]=='.' && str[pos+1]!='.') || (str[pos-1]!='.' && str[pos+1]=='.')){
						adj++;
					}
					else{
						groups++;
						adj++;
					}
				}
				else if(hasleft){
					if(str[pos-1]!='.'){
						groups++;
						adj++;
					}
					else{
						adj++;
					}
				}
				else if(hasright){
					if(str[pos+1]!='.'){
						groups++;
						adj++;
					}
					else{
						adj++;
					}
				}
			}
		}
		str[pos]=c;
		//groups and adj updated
		cout << adj - groups << endl;
	}
	//cout << groups << " " << adj << endl;
}

