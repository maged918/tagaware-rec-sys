//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    cout << v[1] - v[0] << " " << v[n-1] - v[0] << "\n";
    for(int i=1;i<n-1;i++){
        cout << min(v[i+1] - v[i],v[i] - v[i-1]) << " " << max(v[n-1] - v[i],v[i] - v[0]) << "\n";
    }
    cout << v[n-1] - v[n-2] << " " << v[n-1] - v[0] << "\n";
    return 0;
}