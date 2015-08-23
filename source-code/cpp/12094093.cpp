//Language: GNU C++11


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define L(u) u<<1
#define R(u) u<<1|1
#define MID(l, r) (l+r)>>1

int cnt[26];

struct Node{
	int left, right, value;
	int lazy_tag;
};
class STree
{
public:
	enum MAXN {maxn=400020};
	//enum MAXN { maxn = 1000 };
	Node nodes[maxn];

	void build(int l, int r, int id){
		nodes[id].left = l;
		nodes[id].right = r;
		nodes[id].value = 0;
		nodes[id].lazy_tag = 0;

		if (l + 1 == r){
			return;
		}
		build(l, MID(l, r), L(id));
		build(MID(l, r), r, R(id));
	}

	void pushDown(int l, int r, int id){
		if (nodes[id].lazy_tag == 0) return;

		if (nodes[id].lazy_tag == 1){
			nodes[id].lazy_tag = 0;
			nodes[L(id)].value = (nodes[L(id)].right - nodes[L(id)].left);
			nodes[R(id)].value = (nodes[R(id)].right - nodes[R(id)].left);
			nodes[L(id)].lazy_tag = 1;
			nodes[R(id)].lazy_tag = 1;
		}
		else if (nodes[id].lazy_tag == 2){
			nodes[id].lazy_tag = 0;
			nodes[L(id)].value = nodes[R(id)].value = 0;
			nodes[L(id)].lazy_tag = 2;
			nodes[R(id)].lazy_tag = 2;
		}
	}

	void update(int l, int r, int id, int value){
		if (nodes[id].left == l && nodes[id].right == r){
			if (value == 0){
				nodes[id].lazy_tag = 2;
				nodes[id].value = 0;
			}
			else{
				nodes[id].value = nodes[id].right - nodes[id].left;
				nodes[id].lazy_tag = 1;
			}

			return;
		}
		else{
			pushDown(nodes[id].left, nodes[id].right, id);
			int mid = MID(nodes[id].left, nodes[id].right);
			if (r <= mid) update(l, r, L(id), value);
			else if (l >= mid) update(l, r, R(id), value);
			else{
				update(l, mid, L(id), value);
				update(mid, r, R(id), value);
			}
			nodes[id].value = nodes[L(id)].value + nodes[R(id)].value;
		}
	}

	int query(int l, int r, int id){
		if (nodes[id].left == l && nodes[id].right == r){
			return nodes[id].value;
		}

		int mid = MID(nodes[id].left, nodes[id].right);
		int ans;
		pushDown(nodes[id].left, nodes[id].right, id);

		if (r <= mid) ans = query(l, r, L(id));
		else if (l >= mid) ans = query(l, r, R(id));
		else ans = (query(l, mid, L(id)) + query(mid, r, R(id)));

		nodes[id].value = nodes[L(id)].value + nodes[R(id)].value;
		return ans;
	}
};
int main()
{
	STree trees[26];
	char str[100010];

	int n, q;
	//cin >> n >> q;
	scanf("%d%d", &n, &q);
	scanf("%s", str);
	//cin >> str;

	for (int i = 0; i < 26; i++){
		trees[i].build(1, n + 1, 1);
	}

	for (int i = 1; i <= n; i++){
		trees[str[i-1] - 'a'].update(i, i + 1, 1, 1);
	}

	int a, b, c;

	for (int i = 0; i < q; i++)
	{
		//cin >> a >> b >> c;
		scanf("%d%d%d", &a, &b, &c);
		memset(cnt, 0, sizeof(cnt));

		for (int j = 0; j < 26; j++){
			cnt[j] += trees[j].query(a, b + 1, 1);
			trees[j].update(a, b + 1, 1, 0);
		}

		if (c == 1){
			int l = a, r = a + 1;
			for (int k = 0; k < 26; k++){
				if (cnt[k] == 0) continue;

				r = l + cnt[k];
				trees[k].update(l, r, 1, 1);
				l = r;
			}
		}
		else{
			int l = a, r = a + 1;
			for (int k = 25; k >= 0; k--){
				if (cnt[k] == 0) continue;

				r = l + cnt[k];
				trees[k].update(l, r, 1, 1);
				l = r;
			}
		}
	}

	for (int p = 1; p <= n; p++){
		for (int q = 0; q < 26; q++){
			if (trees[q].query(p, p+1, 1) != 0){
				str[p - 1] = (char)('a' + q);
				break;
			}
		}
	}
//	cout << str << endl;
	printf("%s\n", str);
	return 0;
}