//Language: GNU C++11


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
int n;
int a[100001];
int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<int,int> rmp,mp,lmp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if (!lmp.count(a[i])){
            lmp[a[i]] = i;
            rmp[a[i]] = i;
        }
        else rmp[a[i]] = i;
    }
    int best = -1;
    int ele;
    for(auto it=mp.begin();it!=mp.end();it++){
        //cout << it->first << ", " << it->second << "; " << ele << "," << best << "\n";
        if (it->second>best) {
            best = it->second;
            ele = it->first;
        }
        else if (it->second==best){
            if (rmp[it->first]-lmp[it->first]<rmp[ele]-lmp[ele]){
                best = it->second;
                ele = it->first;
            }
            
            
        }
    }
    cout << lmp[ele]+1 << " " << rmp[ele]+1;
    return 0;
}
