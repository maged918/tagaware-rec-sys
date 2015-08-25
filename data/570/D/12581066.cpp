//Language: GNU C++11


#include <bits/stdc++.h> 

#define ll long long
#define md 1000000007LL
#define EPS 0.000000000001


using namespace std;

vector<int> a[500001];
vector<pair<int, int> > h[500001];
int in[500001], out[500001];

void dfs(int cur, int &time, int level) 
{
    time++;
    in[cur] = time;
    h[level].emplace_back(time, cur);

    for (int i = 0; i < (int)a[cur].size(); i++) 
    {
        dfs(a[cur][i], time, level + 1);
    }

    time++;

    out[cur] = time;
}

bool cmp(pair<int, int> f, pair<int, int> s) 
{
   return f.first < s.first; 
}

char buf[500001];
vector<int> letters[26][500001];

void fill_letters() 
{
    for (int i = 0; i < 500001; i++) 
    {

        for (int j = 0; j < (int)h[i].size(); j++) 
        {
            int letter = buf[h[i][j].second] - 'a';
            if (letters[letter][i].size() == 0) 
            {
                letters[letter][i].resize(h[i].size());
            }

            letters[letter][i][j]++;
        }

        for (int j = 0; j < 26; j++) 
        {
            for (int z = 1; z < (int)letters[j][i].size(); z++) 
            {
                letters[j][i][z] += letters[j][i][z - 1];
            }

        }
    }

}

bool getans(int l, int r, int h) 
{
    int k = 0;
//    cout << l << " " << r << endl;
    for (int i = 0; i < 26; i++) 
    {
        /*
        printf("%c : ", i + 'a');
        for (int j = 0; j < (int)letters[i][h].size(); j++) 
        {
            cout << letters[i][h][j] << " ";
        }
        cout << endl;
       */
        if (letters[i][h].size() == 0) 
        {
            continue;
        }

        int ans = letters[i][h][r];
        if (l != 0) 
        {
            ans -= letters[i][h][l - 1];
        }
        
        k += ans % 2;
    }

    return k < 2;
}




int main()
{
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
    #endif //DEBUG
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n - 1; i++) 
    {
        int x;
        scanf("%d", &x);
        a[x - 1].push_back(i + 1);
    }

    scanf("\n");
    gets(buf);

    int time = 0;
    dfs(0, time, 1);

    fill_letters();

    for (int i = 0; i < m; i++) 
    {
        int v, d;
        scanf("%d %d", &v, &d);

        int l = in[v - 1];
        int r = out[v - 1];
        
        int lo = lower_bound(h[d].begin(), h[d].end(), make_pair(l, 0), cmp) - h[d].begin();
        int hi = upper_bound(h[d].begin(), h[d].end(), make_pair(r, 0), cmp) - h[d].begin();
        if (hi) hi--;
        
        if (!h[d].size() || getans(lo, hi, d)) 
        {
            printf("Yes\n");
        } else 
        {
            printf("No\n");
        }
    }


    fprintf(stderr, "Execution time = %.4lfsec", (double)clock() / (double)CLOCKS_PER_SEC);    
    return 0;
}
