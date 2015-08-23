//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int a[100001];
int cnt[100001];
vector <int> rems;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == 0)
        {
            rems.push_back(i);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(cnt[a[i]] > 1 || a[i] > n)
        {
            cnt[a[i]]--;
            a[i] = rems[rems.size()-1];
            rems.pop_back();
            cnt[a[i]] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}