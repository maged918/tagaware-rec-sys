//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct node{
	int val, lazy;
	node(){
		val = lazy = 0;
	}
} seg[26][4*N];

char A[N];
int cnt[30];

void lazy_push(int index, int nd, int l, int r){
	if(seg[index][nd].lazy != 0){
		if(l != r)	seg[index][nd*2].lazy = seg[index][nd*2 + 1].lazy = seg[index][nd].lazy;
		if(seg[index][nd].lazy == 1)	seg[index][nd].val = r - l + 1;
		else seg[index][nd].val = 0;
		seg[index][nd].lazy = 0;
	}
}

void update(int nd, int l, int r, int index, int x, int y, int lazy_val){
	lazy_push(index, nd, l, r);
	if(l > y or r < x)	return ;
	else if(l >= x and r <= y){
		seg[index][nd].lazy = lazy_val;
		lazy_push(index, nd, l, r);
	}
	else{
		int mid = (l + r)/2;
		update(nd*2, l, mid, index, x, y, lazy_val);
		update(nd*2 + 1, mid + 1, r, index, x, y, lazy_val);
		seg[index][nd].val = seg[index][nd*2].val + seg[index][nd*2 + 1].val;
	}
}

int query(int nd, int l, int r, int index, int x, int y){
	lazy_push(index, nd, l, r);
	if(l > y or r < x)	return 0;
	else if(l >= x and r <= y)	return seg[index][nd].val;
	else{
		int mid = (l + r)/2;
		return (query(nd*2, l, mid, index, x, y) + query(nd*2 + 1, mid + 1, r, index, x, y));
	}
}

int main(){

	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 4*N; j++)
			seg[i][j].val = seg[i][j].lazy = 0;

	int n, q, l, r, k, start, temp;

	cin>>n>>q;
	cin>>A;


	for(int i = 0; i < n; i++)	update(1, 1, n, A[i] - 'a', i + 1, i + 1, 1);

	while(q--){
		cin>>l>>r>>k;
		for(int i = 0; i < 26; i++){
			cnt[i] = query(1, 1, n, i, l, r);
			//cout<<i<<" --> "<<cnt[i]<<endl;
			update(1, 1, n, i, l, r, -1);
		}
		start = l;
		for(int i = 25; i >= 0; i--){
			if(k)	temp = 25 - i;
			else temp = i;
			if(cnt[temp])
				update(1, 1, n, temp, start, start + cnt[temp] - 1, 1), start += cnt[temp];
		}
	}

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 26; j++)
			if(query(1, 1, n, j, i, i) == 1){
				char temp = 'a' + j;
				cout<<temp;
			}
	cout<<endl;

	return 0;
}