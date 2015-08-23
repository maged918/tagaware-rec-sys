//Language: GNU C++11


// AUthor: thecodekaiser
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MXN 300100

string str;

struct Node
{
	int left, right, len, ans;

}tree[MXN * 4];

void build(int Node, int l, int r)
{
	if(l > r)
		return;

	if(l == r)
	{
		if(str[l] == '.')
		{
			tree[Node].left = tree[Node].right = 1;
			tree[Node].ans = 0;
		}
		else
		{
			tree[Node].left = tree[Node].right = 0;
			tree[Node].ans = 0;
		}
		tree[Node].len = 1;
		return;
	}

	int mid = (l+r)/2, left = 2*Node, right = 2*Node+1;

	build(left, l, mid);
	build(right, mid+1, r);

	if(tree[right].right == tree[right].len)
		tree[Node].right = tree[right].right + tree[left].right;
	else
		tree[Node].right = tree[right].right;

	if(tree[left].left == tree[left].len)
		tree[Node].left = tree[left].left + tree[right].left;
	else
		tree[Node].left = tree[left].left;

	if(tree[left].right >= 1 and tree[right].left >= 1)
		tree[Node].ans = (tree[left].ans - (tree[left].right-1)) + (tree[right].ans - (tree[right].left-1)) + (tree[left].right + tree[right].left - 1);
	else
		tree[Node].ans = (tree[right].ans + tree[left].ans);

	tree[Node].len = tree[left].len + tree[right].len;
	return;

}

void update(int Node, int l, int r, int i, int j)
{
	if(l > r or j < l or r < i)
		return;

	if(i <= l and r <= j)
	{
		if(str[l] == '.')
		{
			tree[Node].left = tree[Node].right = 1;
			tree[Node].ans = 0;
		}
		else
		{
			tree[Node].left = tree[Node].right = 0;
			tree[Node].ans = 0;
		}
		return;
	}

	int mid = (l+r)/2, left = 2*Node, right = 2*Node+1;

	update(left, l, mid, i, j);
	update(right, mid+1, r, i, j);

	if(tree[right].right == tree[right].len)
		tree[Node].right = tree[right].right + tree[left].right;
	else
		tree[Node].right = tree[right].right;

	if(tree[left].left == tree[left].len)
		tree[Node].left = tree[left].left + tree[right].left;
	else
		tree[Node].left = tree[left].left;

	if(tree[left].right >= 1 and tree[right].left >= 1)
		tree[Node].ans = (tree[left].ans - (tree[left].right-1)) + (tree[right].ans - (tree[right].left-1)) + (tree[left].right + tree[right].left - 1);
	else
		tree[Node].ans = (tree[right].ans + tree[left].ans);

	return;

}

void solve()
{
	int len, Q;
	cin >> len >> Q;

	cin >> str;

	int idx;
	char ch;

	build(1, 0, len-1);
	//cout << tree[1].ans << endl;
	//cout << tree[1].left << " " << tree[1].right << endl;
	for(int i = 0; i < Q; i++)
	{
		scanf("%d %c", &idx, &ch);
		idx--;
		str[idx] = ch;

		update(1, 0, len-1, idx, idx);
		printf("%d\n", tree[1].ans);
	}
	return;
}

int main()
{
	solve();
	return 0;
}