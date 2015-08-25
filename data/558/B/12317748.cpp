//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int qtd[1000010];
int vet[1000000];
int lo[1000000];
int hi[1000000];

vector < pair < int, int > > ans;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> vet[i];
        if( qtd[vet[i]] == 0 ) lo[vet[i]] = i;
        qtd[vet[i]]++;
        hi[vet[i]] = i;
    }
    for( int i = 0; i <= 1000000; i++ ){
        if( qtd[i] ) ans.push_back(make_pair(qtd[i], i));
    }
    sort(ans.begin(), ans.end());
    int tot = 1e9, p = ans.size()-1;
    for( int i = ans.size()-1; i >= 0 && ans[i].first == ans.back().first; i-- ){
        int r = (hi[ans[i].second] - lo[ans[i].second]) + 1;
        if( r < tot ){
            tot = r;
            p = i;
        }
    }
    cout << lo[ans[p].second]+1 << " " << hi[ans[p].second]+1 << '\n';
    return 0;
}