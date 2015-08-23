//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
using namespace std;
vector <int> v[27];
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < s.size(); ++i){
        v[s[i] - 'a'].push_back(i);
    }
    while (q--){
        int l, r, c;
        cin >> l >> r >> c;
        --l;
        --r;
        if (c){
            int cnt = l;
            for (int i = 0; i <= 26; ++i){
                int ss = lower_bound(v[i].begin(), v[i].end(), l) - v[i].begin();
                int ff = upper_bound(v[i].begin(), v[i].end(), r) - v[i].begin();
                if(ss==ff)continue;
                //cout<<ss<<" "<<ff<<endl;
                for (int j = ss; j < ff; ++j)
                {
                   // cout<<v[i][j]<<" "<<cnt<<endl;
                    v[i][j] = cnt;
                    ++cnt;
                }
            }
        }
        else{
            int cnt = l;
            for (int i = 26; i >= 0; --i){
                int ss = lower_bound(v[i].begin(), v[i].end(), l) - v[i].begin();
                int ff = upper_bound(v[i].begin(), v[i].end(), r) - v[i].begin();
                for (int j = ss; j < ff; ++j){
                    v[i][j] = cnt;
                    ++cnt;
                }
            }
        }
    }
    for (int i = 0; i < 27; ++i){
        for (int j = 0; j < v[i].size(); ++j){
            s[v[i][j]] = char('a' + i);
        }
    }
    cout << s << endl;
}
