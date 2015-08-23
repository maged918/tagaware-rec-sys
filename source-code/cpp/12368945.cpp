//Language: MS C++


#include <iostream>
#include <set>
using namespace std;
set < int > s;
set < int > :: iterator it, it1, it2;
int n;
int a, k;
int mx;
int m, x;
int ans = -1;
int main(){
    cin >> n >> k >> a;
    s.insert(n+1);
    s.insert(0);
    cin >> m;
    mx = (n+1)/(a+1);
    if(mx < k){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= m; ++i){
        cin >> x;
        s.insert(x);
        it = s.find(x);
        it1 = it, it2 = it;
        it1 --;
        it2 ++;
        int l = (*it1), mi = (*it), r = (*it2);
        mx -= (r-l)/(a+1);
        mx += (mi-l)/(a+1);
        mx += (r-mi)/(a+1);
        if(mx < k){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}