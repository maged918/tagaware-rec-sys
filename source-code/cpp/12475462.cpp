//Language: GNU C++11


#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<ctype.h>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<math.h>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<stdio.h>
#include<stdlib.h>
#include<streambuf>
#include<string.h>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#define md 1000000007
using namespace std;
long long c[4010][4010],b[4010];
int main(){
	c[0][0]=1;
	for(int i=1;i<=4001;i++){
		c[i][0]=1;
		for (int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=md;
		}
	}
	int n;
	cin>>n;
	b[0]=1;
	for (int i=1;i<=n+1;i++){
		for(int j=0;j<i;j++){
			b[i]+=c[i-1][j]*b[j];
			b[i]%=md;
		}
	}
	cout<<(b[n+1]-b[n]+md)%md;
	return 0;
}
	     				 	  	 		  	  	  					