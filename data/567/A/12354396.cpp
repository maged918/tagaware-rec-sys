//Language: GNU C++11


/*Krypto...........................jagsxi..........!!! */
/* Hackerrank Code Sprint 2015 */
/* P.S- I am always hungry :) */
 
#include<bits/stdc++.h>
using namespace std;
//int dynr[1000005];
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define rep(i,a, b) for (int i = int(a); i < int(b); i++) // a to b, and variable i is local! 
#define repe(i,a, b) for (long long int i = long long int(a); i <= long long int(b); i++) 
#define nrep(i,a,b) for (int i = int(a); i >= int(b); i--)
long long int gcd(long long int a, long long int b) { if (a < 0 || b < 0)
    return gcd(abs(a), abs(b));
    if (a == 0) return b; else return gcd (b % a, a); }
/*Use like- 
rep(i,0,n - 1)
*/

template<class T> T pwr(T b, T ar){T r=1,pr2=b;while(ar){if(ar&1)r*=pr2;pr2*=pr2;ar=(ar>>1);}return r;}
void remove(int a[], long pos, long &n)
{
    
}    


int main() {
 int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout<<arr[1]-arr[0]<<" "<<arr[n-1]-arr[0]<<endl;
for(int i=1;i<(n-1);i++){
    cout<<min(arr[i+1]-arr[i],arr[i]-arr[i-1])<<" "<<max(arr[i]-arr[0],arr[n-1]-arr[i])<<endl;
}
cout<<arr[n-1]-arr[n-2]<<" "<<arr[n-1]-arr[0]<<endl;
}