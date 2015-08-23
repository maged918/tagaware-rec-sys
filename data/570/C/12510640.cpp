//Language: GNU C++11


#include<cstdio>
#include<algorithm>
using namespace std;
const int S = 1<<19;

struct tree
{
	int tab[2*S];
	bool p[2*S];
	bool k[2*S];
	
	int query()
	{
		return tab[1]; 
	}
	
	void insert(int pos, bool kropka){
		pos+=S;
		tab[pos] = 0;
		p[pos] = kropka;
		k[pos] = kropka;
		pos/=2;
		while (pos > 0)
		{
			tab[pos] = tab[pos*2] + tab[pos*2+1];
			p[pos] = p[pos*2];
			k[pos] = k[pos*2+1];
			if (k[pos*2] && p[pos*2+1])
				tab[pos]++;
			pos/=2;
		}
		
	}
	
	
};

tree t;


int main ()
{
	int n, m;
	char a;
	int b;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf (" %c", &a);
		t.insert(i, a == '.');
	}
	for (int j = 0; j < m; j++)
	{
		scanf ("%d %c", &b, &a);
		t.insert(b-1, a=='.');
		printf("%d\n", t.query());
	//	for (int i = 0; i < S; i++)
	//		printf("%d ", t.p[i+S]);
		
	}
	return 0;
}