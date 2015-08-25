//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> v(n);
    int min1 = 1e9;
    for(int x=0; x<n; x++) {
        int t; cin >> t; string s = "";
        for(int y=30; y>=0; y--)
            if(1<<y <= t)
                s+=(t&(1<<y)?'1':'0');
        min1 = min(min1, (int)s.length());
        v[x]=s;
    }
    int b1 = 0;
    for(int x=0; x<min1; x++) {
        bool b = 1;
        char c = '-';
        for(int y=0; y<n; y++) {
                if(c=='-') c=v[y][x];
                else if(v[y][x]!=c) {b=0; break;}
            }
        if(b) b1++;
        else break;
    }
    int t = 0, ans=0;
    for(int x=0; x<n; x++) {
        int b2 = v[x].length(), o=v[x].length();
        for(int y=b1; y<v[x].length(); y++)
            if(v[x][y]=='1') {b2=y; break;}
        v[x] = v[x].substr(0, b2);
        ans += o-v[x].length();
        t += v[x].length();
    }
    int ans2 = 1e9;
    for(int x=0; x<=30; x++) {
        int tmp = 0;
        for(int y=0; y<n; y++)
            tmp += abs((int)v[y].length()-x);
        ans2 = min(tmp, ans2);
    }
    cout << ans+ans2;
}