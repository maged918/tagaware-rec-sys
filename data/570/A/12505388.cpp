//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, x, y, may;
	scanf("%d %d", &n , &m);
	vector<int> V(n, 0);
	for (int i = 0; i < m; ++i){
		may=-1;
		for (int j = 0; j < n; ++j){
			scanf("%d", &x);
			if(x>may)
				may=x, y=j;
		}
		V[y]++;
	}

	may=-1;
	for (int i = 0; i < V.size(); ++i){
		if(V[i]>may)
			may=V[i], y=i;
	}
	printf("%d", y+1);

return 0;	
}