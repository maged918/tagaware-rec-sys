//Language: GNU C++


#include <bits\stdc++.h>
using namespace std;

#define REPi(a, b)  for(register int i = a, endi = b; i <= endi; i ++)
#define REPj(a, b)  for(register int j = a, endj = b; j <= endj; j ++)
#define REPk(a, b)  for(register int k = a, endk = b; k <= endk; k ++)
#define uREPi(a, b) for(register int i = a, endi = b; i >= endi; i --)
#define uREPj(a, b) for(register int j = a, endj = b; j >= endj; j --)
#define uREPk(a, b) for(register int k = a, endk = b; k >= endk; k --)
#define Pqueue      priority_queue <int, vector <int>, greater<int> >
#define NEW(Node)   (Node *) malloc (sizeof(Node))
#define debug(...)  fprintf(stderr, __VA_ARGS__)
#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define MS(a, b)    memset(a, b, sizeof(a))
#define mp          make_pair
#define pb          push_back
#define AA          first
#define BB          second

inline void in(){freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
inline void out(){fclose(stdin); fclose(stdout);}

inline void Read(int &k){
	register char QAQ;
	while((QAQ = getchar()) < '0' || QAQ > '9');
	k = QAQ - '0';
	while(1){if((QAQ = getchar()) < '0' || QAQ > '9')break; k = (k << 1) + (k << 3) + QAQ - '0';}
}

int a1, a2, a3, b1, b2, b3;

inline void Init(){
	Read(a1), Read(b1);
	Read(a2), Read(b2);
	Read(a3), Read(b3);
}

inline void Pre(){
	
}

bool ans = false;

inline void Solve(){
	if(a1 * b1 < a2 * b2 + a3 * b3) return ;
	if(a2 + a3 <= a1 && MAX(b2, b3) <= b1) ans = true;
	if(a2 + b3 <= a1 && MAX(b2, a3) <= b1) ans = true;
	if(b2 + a3 <= a1 && MAX(a2, b3) <= b1) ans = true;
	if(b2 + b3 <= a1 && MAX(a2, a3) <= b1) ans = true;
	
	if(a2 + a3 <= b1 && MAX(b2, b3) <= a1) ans = true;
	if(a2 + b3 <= b1 && MAX(b2, a3) <= a1) ans = true;
	if(b2 + a3 <= b1 && MAX(a2, b3) <= a1) ans = true;
	if(b2 + b3 <= b1 && MAX(a2, a3) <= a1) ans = true;
}

inline void Print(){
	puts(ans ? "YES" : "NO");
}

int main(){
	#ifndef ONLINE_JUDGE
	in();
	#endif

	Init();
	Pre();
	Solve();
	Print();

	#ifndef ONLINE_JUDGE
	out();
	#endif
	return 0;
}
