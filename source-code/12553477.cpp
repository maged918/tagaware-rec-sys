//Language: GNU C++


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

vector <int> used;
vector <vector <int> > A;
vector <vector <pair <int, char> > > G;
vector <vector  <int> > Answer;
vector <int> tin;
vector <int> tout;
int time = 0;
string s;

void dfs(int v, int deep)
{
    used[v] = 1;
    tin[v] = time++;
    G[deep].push_back(make_pair(v, s[v]));
    for (int i = 0; i < A[v].size(); i++)
    {
        int u = A[v][i];
        if (!used[u])
            dfs(u, deep + 1);
    }
    tout[v] = time++;
}

int main()
{
    int n, m, p, v, h;
    scanf("%d %d\n", &n, &m);
    A.resize(n);
    used.resize(n, 0);
    G.resize(n);
    tin.resize(n);
    tout.resize(n);
    Answer.resize(n);
    for (int i = 1; i < n; i++)
    {
        cin >> p;
        p--;
        A[p].push_back(i);
    }
    scanf("\n");
    getline(cin, s);
    dfs(0, 0);
    for (int i = 0; i < n; i++)
    {
        int szz = G[i].size() + 1;
        Answer[i].resize(szz, 0);
        for (int j = 1; j < szz; j++)
        {
            int num = int(G[i][j - 1].second - 'a');
            Answer[i][j] = Answer[i][j - 1];
            Answer[i][j] ^= (1 << num);
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &v, &h);
        v--;
        h--;
        int high = h;
        int sz = G[high].size();
        if (sz == 0)
        {
            printf("Yes\n");
            continue;
        }
        int l = 0, r = sz, left, right;
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            int u = G[high][mid].first;
            if (tin[u] <= tin[v])
                l = mid;
            else
                r = mid;
        }

        if (tin[G[high][l].first] >= tin[v])
            left = l;
        else
            left = r;
        if (left >= sz || (tout[v] < tout[G[high][left].first]))
        {
            printf("Yes\n");
            continue;
        }

        int l1 = left, r1 = sz;
        while (r1 - l1 > 1)
        {
            int mid = (r1 + l1) / 2;
            int u = G[high][mid].first;
            if (tout[v] > tout[u])
                l1 = mid;
            else
                r1 = mid;
        }

        if (tout[v] >= tout[G[high][l1].first])
            right = l1;
        else
            right = r1;
        if (right >= sz || (left == right))
        {
            printf("Yes\n");
            continue;
        }
        int odd = 0;
        int chislo = Answer[high][right + 1] ^ Answer[high][left];
        while (chislo > 0)
        {
            if (chislo % 2 == 1)
                odd++;
            chislo /= 2;
        }
        if (odd > 1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
