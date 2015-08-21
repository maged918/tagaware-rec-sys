//Language: GNU C++11


#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define LCH(i) (2 * i)
#define RCH(i) (2 * i + 1)
const int maxn = 1e5;
const int maxl = 26;
const int maxo = 50000;
using namespace std;

struct OP
{
	int l, r, ope;
}op[maxo + 5], sta[maxo + 5];

struct T
{
	int lc, rc, cnt;
	int size(){
		if(lazy == 1)return rc - lc + 1;
		else return 0;
	}
	int lazy;
}tree[maxl + 5][maxn * 4];

int n, q, top, tmp[maxl + 5];
char str[maxn + 5];

void del()
{
	for(int i = 1; i <= q; i ++){
		while(top > 0 && sta[top].l >= op[i].l && sta[top].r <= op[i].r) -- top;
		sta[++ top] = op[i];
	}
	for(int i = 1; i <= top; i ++)
		op[i] = sta[i];
	q = top;
}

void built(int i, int l, int r, int alpha)
{
	tree[alpha][i].lc = l, tree[alpha][i].rc = r;
	if(l == r){
		if(str[l] - 'a' == alpha)tree[alpha][i].cnt ++;
		return ;
	}
	int mid = (l + r) / 2;
	built(LCH(i), l, mid, alpha);
	built(RCH(i), mid + 1, r, alpha);
	tree[alpha][i].cnt = tree[alpha][LCH(i)].cnt + tree[alpha][RCH(i)].cnt;
	return;
}

void query(int i, int l, int r, int alpha){
	if(tree[alpha][i].rc < l || tree[alpha][i].lc > r)return ;
	if(tree[alpha][i].lc >= l && tree[alpha][i].rc <= r){
		tmp[alpha] += tree[alpha][i].cnt;
		tree[alpha][i].lazy = 1;
		return;
	}
	else {
		if(tree[alpha][i].lazy){
			tree[alpha][LCH(i)].lazy = tree[alpha][i].lazy;
			tree[alpha][RCH(i)].lazy = tree[alpha][i].lazy;
			tree[alpha][LCH(i)].cnt = tree[alpha][LCH(i)].size();
			tree[alpha][RCH(i)].cnt = tree[alpha][RCH(i)].size();
			tree[alpha][i].lazy = 0;
		}
		query(LCH(i), l, r, alpha);
		query(RCH(i), l, r, alpha);
	}
}

void update(int i, int l, int r, int alpha, int val)
{
	if(tree[alpha][i].lc > r || tree[alpha][i].rc < l)return;
	if(tree[alpha][i].lc >= l && tree[alpha][i].rc <= r){
		tree[alpha][i].lazy = val;
		tree[alpha][i].cnt = tree[alpha][i].size();
		return;
	}
	else {
		if(tree[alpha][i].lazy){
			tree[alpha][LCH(i)].lazy = tree[alpha][i].lazy;
			tree[alpha][RCH(i)].lazy = tree[alpha][i].lazy;
			tree[alpha][LCH(i)].cnt = tree[alpha][LCH(i)].size();
			tree[alpha][RCH(i)].cnt = tree[alpha][RCH(i)].size();
			tree[alpha][i].lazy = 0;
		}
		update(LCH(i), l, r, alpha, val);
		update(RCH(i), l, r, alpha, val);
		tree[alpha][i].cnt = tree[alpha][LCH(i)].cnt + tree[alpha][RCH(i)].cnt;
		return;
	}
}

int main()
{
	scanf("%d %d\n", &n, &q);
	gets(str + 1);
	for(int i = 1; i <= q; i ++)
		scanf("%d%d%d", &op[i].l, &op[i].r, &op[i].ope);
	del();
	for(int i = 0; i < maxl; i ++)
		built(1, 1, n, i);
	
	int xlen;
	for(int i = 1; i <= q; i ++){
		for(int j = 0; j < maxl; j ++){
			query(1, op[i].l, op[i].r, j);
			update(1, op[i].l, op[i].r, j, 2);
		}
		xlen = op[i].l;
		if(op[i].ope){
			for(int j = 0; j < maxl; j ++){
				if(!tmp[j])continue;
				update(1, xlen, xlen + tmp[j] - 1, j, 1);
				while(tmp[j]){
					str[xlen ++] = j + 'a';
					tmp[j] --;
				}
			}
		}
		else{
			for(int j = maxl - 1; j >= 0; j --){
				if(!tmp[j])continue;
				update(1, xlen, xlen + tmp[j] - 1, j, 1);
				while(tmp[j]){
					str[xlen ++] = j + 'a';
					tmp[j] --;
				}
			}
		}
		//printf("%s", str + 1);
		//puts("");
	}
	printf("%s", str + 1);
}