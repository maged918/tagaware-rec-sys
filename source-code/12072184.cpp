//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

vector <int> vec;
map <int, int> mp;


int main()
{
    int lx = 0, rx = 0, mn, n, beat = 0;
    cin >> n;
    rx = n - 1;
    mn = n;
    vec.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (mp.find(vec[i]) == mp.end()) mp[vec[i]] = 0;
        beat = max(beat, ++mp[vec[i]]);
    }
    int j = 0, pr_mx = vec[0], wt = -1;
    mp.clear();
    for (int i = 0; i < n; i++)
    {
        for(; j < n && mp[pr_mx] != beat; j++)
        {
            if(mp.find(vec[j]) == mp.end())
            {
                mp[vec[j]] = 0;
            }
            if(wt != j)
            {
                wt = j;
                mp[vec[j]]++;
            }
            if (beat == mp[vec[j]])
            {
                pr_mx = vec[j];
                break;
            }
        }
        if (j == n) break;
        if (mn > j - i + 1)
        {
            mn = j - i + 1;
            lx = i, rx = j;
        }
        mp[vec[i]]--;
    }
    cout << lx + 1 << ' ' << rx + 1;
    return 0;
}
