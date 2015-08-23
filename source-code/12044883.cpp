//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int, int> a[1000];
string s;

int main(){
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else

#endif //LOCAL
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n);
    int fr = 200, fl = -1;
    for (int i=0;i<n;i++){
        if (a[i].first < 0)
            fl = i;
        if (a[i].first > 0 && fr == 200)
            fr = i;
    }
    int tmp = 0;
    int now = 1;
    while ((fl != -1 || now == 1) && (fr != 200 || now == 0)){
        if (now == 1){
            tmp += a[fr].second;
            fr++;
            if (fr >= n)
                fr = 200;
            now = 0;
        }
        else{
            tmp += a[fl].second;
            fl--;
            if (fl < 0)
                fl = -1;
            now = 1;
        }
    }
    int ans = tmp;
    tmp = 0;
    now = 0;
    fr = 200;
    fl = -1;
    for (int i=0;i<n;i++){
        if (a[i].first < 0)
            fl = i;
        if (a[i].first > 0 && fr == 200)
            fr = i;
    }
    while ((fl != -1 || now == 1) && (fr != 200 || now == 0)){
        if (now == 1){
            tmp += a[fr].second;
            fr++;
            if (fr >= n)
                fr = 200;
            now = 0;
        }
        else{
            tmp += a[fl].second;
            fl--;
            if (fl < 0)
                fl = -1;
            now = 1;
        }
    }
    cout << max(ans, tmp) << endl;
    return 0;
}
