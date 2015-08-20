//Language: GNU C++11


//
#include <bits/stdc++.h>
using namespace std;

const int  INF = std::numeric_limits<int>::max()/3;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define eps (1.0e-9)
#define are_equal(a,b)fabs((a)-(b))<eps
#define abs_val(a)((a)>=0)?(a):(-(a))
#define LS(b)(b&(-(b))) // Least significant bit
#define DEG_to_RAD(a)(((a)*PI)/180.0) // convert to radians
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//
#define MAX_P 2000000
bitset<MAX_P> isprime;
bitset<MAX_P> ispalinprime;
int primes[MAX_P];
int palin_primes[MAX_P];

bool isPalin(int n){
    vi digits;

    while(n){
        digits.push_back(n % 10);
        n /= 10;
    }

    int i = 0, j = digits.size()-1;

    if(digits[i] == 0 || digits[j] == 0)
        return false;

    while(i < j){
        if(digits[i] != digits[j])
            return false;
        i++, j--;
    }
    return true;
}

void sieve(){
    isprime.set();
    for (int i = 4; i < MAX_P; i += 2)
        isprime[i] = false;
    for (int i = 3; i*i < MAX_P; i+=2)
        if(isprime[i])
            for (int j = i*i; j < MAX_P; j+=i)
                isprime[j] = false;

}


int main(){
    FASTER;
    sieve();

//  printf("ispalin prime = %d\n", isPalin(13));
//  printf("ispalin prime = %d\n", (int)ispalinprime[13]);

    MEM(primes, 0);
    MEM(palin_primes, 0);

    for (int i = 2; i < MAX_P; ++i) {
        primes[i] = isprime[i] + primes[i-1];
    }

    for (int i = 1; i < MAX_P; ++i) {
        palin_primes[i] = isPalin(i) + palin_primes[i-1];
//      if(i < 20)printf("palin_primes[%d] = %d\n", i, palin_primes[i]);
    }

    int p,q;
    cin >> p >> q;

    double A = p /(double) q;
//  printf("A = %lf\n", A);
    int n;
    for (n = MAX_P-1; n >= 0; --n) {
        double a = 1.0*primes[n];
        double b = A*palin_primes[n];
        if(fabs(a - b) < eps || a  < b){
            break;
        }
    }

//  printf("Debug: %lf %lf\n",1.0*primes[40],A*palin_primes[40] - eps);

    if(n < 0){
        cout << "Palindromic tree is better than splay tree" << endl;
    }else{
        cout << n << endl;
    }

    return 0;
}
