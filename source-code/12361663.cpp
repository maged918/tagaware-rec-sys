//Language: GNU C++11


#include <bits/stdc++.h>
#define LL long long int
#define mod 1000000007

using namespace std;

int main () {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n][2];
    set <int> s;

    int ans = 0,cu = 0,prev=0;
    char ch;

    for(int i=0,j;i<n;i++){
        cin >> ch >> j;
        a[i][1] = j;
        a[i][0] = ch;
        if(ch == '+')
            s.insert(j);
        else {
            if(s.find(j)==s.end())
                prev ++;
            else
                s.erase(j);
        }
    }

   // cout << prev << endl;
    s.clear();
    cu = 0; ans = 0;

     for(int i=0,j;i<n;i++){
        ch = a[i][0];
        j =  a[i][1];

        ans = max(ans,cu+prev);

        if(ch == '+'){
            s.insert(j);
            cu ++;
        }
        else {

            if(s.find(j)==s.end())
                prev --;
            else {
                s.erase(j);
                cu --;
            }
        }
        ans = max(ans,cu+prev);
    }


    cout << ans;

    return 0;
}
