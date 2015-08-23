//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 1000000000LL
#define ll long long

struct node {
    ll a[4];
};

map <ll, node > mymap;
ll ans[200001][4] = {{0}};
ll num[200001];

int main(){
    int i,j;
    ll k,n,key;
    cin >> n >> k;
    map<ll,node >::iterator it;
    
    for(i=1;i<=n;i++) {
        cin >> num[i];
    }
    
    for(i=1;i<=n;i++)
        ans[i][1] = 1;
    
    node temp;
    for(j=0;j<=3;j++)
        temp.a[j] = ans[1][j];
    mymap.insert(pair<ll,node>(num[1],temp));

    for(i=2;i<=n;i++) {
        key = num[i];
        if(key%k==0) {
            it = mymap.find(key/k);
            if(it!= mymap.end()) {
                for(j=2;j<=3;j++) {
                    ans[i][j] = it->second.a[j-1];
                }
            }
        }
        it = mymap.find(key);
        if(it!=mymap.end()) {
            for(j=1;j<=3;j++){
                it->second.a[j] += ans[i][j];
            }
        }
        else {
            node temp;
            for(j=0;j<=3;j++)
                temp.a[j] = ans[i][j];
            mymap.insert(pair<ll,node>(key,temp));
        }
    }
    ll total = 0;
    for(i=1;i<=n;i++)
        total+=ans[i][3];
    cout << total << endl;
    return 0;
}