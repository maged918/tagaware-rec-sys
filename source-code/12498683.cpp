//Language: GNU C++


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <sstream>
#include <cstring>
#include <fstream>
#include <functional>
#include <cstdio>
#include <stack>
#include <utility> 
#include <set>
#include <list>
#include <queue>
#include <bitset>
using namespace std;

#define mem(U, V) memset(U, V, sizeof U)
#define getdis(xa, ya, xb, yb) double(sqrt((xa - xb)*(xa - xb) + (ya - yb)*(ya - yb)))
#define slope(xa, ya, xb, yb) (double)(((double)yb-(double)ya)/((double)xb-(double)xa))

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef set<char> sc;
typedef vector<bool> vb;

const double Pi = 2.0 * acos(0.0);
const double Ex = 2.7182818284;
const int Mod = 1e9 + 7;
const int oo = 2e9 + 1e8;
vi my_loop(int n){
    vi v;
    int x ;
    for(int i = 0 ; i < n ; ++i){
        cin>>x;
        v.push_back(x);
    }
    return v ;

}
//
//ll gcd(ll x, ll y){ return !y ? x : gcd(y, x%y); }
//
//void getInt(int &ret){
//  char tmpc;
//  bool sign = 0;
//  while (tmpc = getchar()){
//      if (tmpc<'0' || tmpc>'9') sign = (tmpc == '-');
//      else break;
//  }
//  ret = tmpc - '0';
//  while (tmpc = getchar(), tmpc >= '0' && tmpc <= '9')
//      ret = ret * 10 + tmpc - '0';
//  if (sign) ret *= -1;
//}
//int string_to_int(string x){
//  int n;
//  n = atoi(x.c_str()) ;
//  return n;
//
//}
//string int_to_string(int x){
//  string r;
//  ostringstream con;
//  con<<x; 
//  r = con.str();
//  return r;
//}
//string str1,str2;
//int memo[100000][1000];
//int F(int i,int j){
//
//  if(i==str1.length()||j==str2.length()) return 0;
//
//  int &x=memo[i][j];
//
//  if(x!=-1)  return x;
//
//  if(str1[i]==str2[j])  return x=1+F(i+1,j+1);
//  
//  int res1=F(i+1,j);
//  
//  int res2=F(i,j+1);
//
//  return x=max(res1,res2);
//
//
//}
//vi prime ;
//vb prime_flag ;
//int max_prime = 10000 ;
//void prime_number(){
//
//  for(int i = 2 ; i*i <= max_prime ; ++i ) 
//      for(int j = i * 2 ; j <= max_prime ; j += i )if(!prime_flag[i]) prime_flag[j] = 1 ;
//
//  for(int i = 2 ; i <= max_prime ; ++i) if(!prime_flag[i]) prime.push_back(i) ;
//
//
//}
/*
int n ;
void dis(int x){

if(x == n+1) return ;

for(int i=0;i<n-x;++i)
cout<<"  ";

for(int i=0;i<=x;++i){
cout<<i;
if(i!=x)
cout<<" ";
}
if(x-1!=-1){
cout<<" ";
for(int i=x-1;i>=0;--i){
cout<<i;
if(i!=0)
cout<<" ";
}
}
cout<<endl;
dis(x+1) ;
if(x!=n){
for(int i=0;i<n-x;++i)
cout<<"  ";

for(int i=0;i<=x;++i){
cout<<i;
if(i!=x)
cout<<" ";
}
if(x-1!=-1){
cout<<" ";
for(int i=x-1;i>=0;--i){
cout<<i;
if(i!=0)
cout<<" ";
}
}
cout<<endl;
}

}
*/

int main(){

    int n , m , in;
    long long x , mini;
    map<int,int> nn ;
    map<int,bool> mm ;
    while(cin>>n>>m){
        mm.clear() ;
        nn.clear() ;
        for(int i=0;i<m;++i){
            mini = -1 ;
            for(int j=0;j<n;++j){

                cin>>x ;

                if(x>mini){

                    in = j + 1 ;
                    mini = x ;
                
                }
            
            }

            if(!mm[in]){
                mm[in] = 1 ;
                nn[in] = 1 ;
            }
            else
                ++nn[in] ;
        
        }
        mini = -1 ;
        for( map<int,int>::iterator it = nn.begin();it!=nn.end();++it){

            if(it->second > mini){
                in = it->first ;
                mini = it->second ;
            
            }
        
        }
        cout<<in<<"\n";
    
    
    }

}