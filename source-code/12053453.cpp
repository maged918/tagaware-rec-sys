//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int h1[1000006];
int h2[1000006];
int h3[1000006];
int main()
{
    int n;
    int x;
    int i;
    int min = 1000000000;
    int l,r;
    int max = 0;
    int a[100005];
    map<int,int> m;
    map<int,int>::iterator it;
    memset(h1,0,sizeof(h1));
    memset(h2,0,sizeof(h2));

    cin>>n;
    for(i = 1; i <= n; i++) {
        cin>>a[i];
        m[a[i]]++;
        if(m[a[i]] > max) {
            max = m[a[i]];
        }
    }

    for(i = 1; i <= n; i++) {
        if(h1[a[i]] == 0) {
            h1[a[i]] = i;
        }
    }
    for(i = n; i >= 1; i--) {
        if(h2[a[i]] == 0) {
            h2[a[i]] = i;
        }
    }
    for(it = m.begin(); it!= m.end(); it++) {
        if(it->second == max) {
           // cout<<h2[it->first]<<' '<<h1[it->first]<<' '<<it->first<<endl;
            if(h2[it->first] - h1[it->first] + 1 < min) {
                min = h2[it->first] - h1[it->first] + 1;
                l = h1[it->first];
                r = h2[it->first];
            }
        }
    }
    cout<<l<<' '<<r;


}
