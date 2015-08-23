//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstring>
#include <climits>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<string,string> pi;
#define bin __builtin_popcount
int a1,a2,a3,b1,b2,b3;

int ok(int x,int y){
    if((x<=a1 && y<=b1) || (x<=b1 && y<=a1)) return 1;  
    return 0;
}

int main (){

cin>>a1>>b1;
cin>>a2>>b2;
cin>>a3>>b3;

int rj=0;

if(ok(a2+a3,max(b2,b3))) rj=1;
if(ok(a2+b3,max(b2,a3))) rj=1;  
if(ok(b2+b3,max(a2,a3))) rj=1;  
if(ok(b2+a3,max(a2,b3))) rj=1;  

(rj)?cout<<"YES":cout<<"NO";    
    
}