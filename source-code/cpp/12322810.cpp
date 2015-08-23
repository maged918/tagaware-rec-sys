//Language: MS C++


#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
using namespace std;
int main()
{
//	FILE* fin = freopen("in.txt","rt", stdin);
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	FOR(i,0,n)
		scanf("%d", &v[i]);

	int cnt[100003];
	bool visited[100003];
	int res[100003];
	memset(cnt, 0, sizeof(cnt));
	memset(res, 0, sizeof(res));
	FOR(i,0,n)
	{
		memset(visited, 0, sizeof(visited));
		
		queue<pair<int, int> > q;
		q.push(make_pair(v[i], 0));
		while(!q.empty())
		{
			int here = q.front().first;
			int qq = q.front().second;
			q.pop();
			visited[here] = true;
			cnt[here]++;
			res[here] += qq;

			if (!visited[here / 2])
			{
				q.push(make_pair(here / 2, qq + 1));
			}
			int there = here * 2;
			if (there < 100003 &&!visited[there])
			{
				q.push(make_pair(there, qq + 1));
			}
		}
	}

	int ret = 987654321;
	FOR(i,0, 100003)
	{
		if (cnt[i] == n && ret > res[i])
			ret = res[i];
	}

	printf("%d\n", ret);

//	fclose(fin);
	return 0;
}
