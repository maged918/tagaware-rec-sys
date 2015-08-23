//Language: GNU C++


#include <cstdio>
#define MAX 100005

using namespace std;

int main (){
	int n, k, a, freq[MAX], seq[MAX], falta[MAX];
	scanf ("%d", &n);
	for (int i = 1; i <= MAX; i++) {
		seq[i] = 0;
		freq[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a);
		freq[a]++;
		seq[i] = a;
	}
	k = 1;
	for (int i = 1; i <= n; i++) {
		if (freq[i] == 0){
			falta[k] = i;
			k++;
		}
	}
	k = 1;
	for (int i = 1; i <= n; i++) {
		if (freq[seq[i]] > 1 || seq[i] > n) {
			freq[seq[i]] -= 1;
			seq[i] = falta[k];
			k++;
		}
	}
	for (int i = 1; i <= n; i++) printf ("%d ", seq[i]);
	printf ("\n");
} 