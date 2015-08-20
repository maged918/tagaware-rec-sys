//Language: GNU C++11


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    long long int n,k,tp,k2,ans=0;
    map<long long int, long long int> mp;
    map<long long int, long long int> mp2;
    cin>>n>>k;
    k2=k*k;
    for (int i=0; i<n; i++) {
        cin>>tp;
        if (k>1) {
            if (tp%k2==0) {
                ans+=mp2[tp/k];
            }
            if (tp%k==0) {
                mp2[tp]+=mp[tp/k];
            }
        }
        else {
            ans+=(mp[tp]*(mp[tp]-1))/2;
        }
        mp[tp]++;
    }
    cout<<ans<<endl;
}