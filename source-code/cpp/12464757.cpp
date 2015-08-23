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
const int maxn = 10000000+5;
bool notPrime[maxn+5];

void Prime(void){
	memset(notPrime,false,sizeof(notPrime));
	for(int i = 2; i*i <= maxn; i++){
		if(!notPrime[i]){
			for(int j = i*i; j <= maxn; j += i){
				notPrime[j] = true;
			}
		}
	}
}
int reverse(int n)  
{  
    int res = 0;  
    while(n)  
    {  
        int d = n % 10;  
        res = res*10 + d;  
        n /= 10;  
    }  
    return res;  
}  
bool hui(int n){
    if(reverse(n) == n) return true;
    else return false;
}
vector<int>v;
int main(){
  //freopen("output.txt","w+",stdout);
    int p,q;
    cin >> p >> q;
    Prime();
    lint pr = 0,hu=0;
    v.clear();
    v.pb(1);
    for(int i = 1 ; i <= 10000000; i++){
        if(!notPrime[i] && i!= 1){
            pr++;
        }
        if(hui(i)){
            hu++;
        }
        //cout << i << endl;
        //cout << pr << " " << hu << endl;
        //cout << hu << endl;
        if(pr * q <= hu*p){
            v.pb(i);
        }
        //p[i] = pr;h[i] = hu;
    }
    if(v.size() >= 1){
        cout <<v[v.size()-1] <<endl;
        return 0;
    }
    cout << "Palindromic tree is better than splay tree" << endl;
    //cout << "p[] = {";
	//for(int i = 2 ; i <= maxn ; i++){
	 //cout << p[i] << " , ";
	//}
	//cout << "}" << endl;
    return 0;
}
