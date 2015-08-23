//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, a, b, c, l, k;
    int arr[100005];
    bool brr[100005] = {0};
    int crr[100005];
    vector <int> v;
    map <int, int> mp;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if(arr[i] <= n && brr[arr[i]] != 1){
            brr[arr[i]] = 1;
            crr[i] = arr[i];
        }
        else
            v.push_back(i);
    }

    /*if(mp.size() == n && brr[n-1] == n)
    {
        for(int i = 0; i < n - 1; i++)
            cout << arr[i] << " ";
        cout << arr[n-1] << endl;
    }

    else
    {*/
    int y = 0;
        for(int i = 1; i <= n; i++)
        {
            if(brr[i] == 0)
            {
                crr[v[y]] = i;
                y++;
            }
        }
        for(int i = 1; i < n; i++)
            cout << crr[i] << " ";
        cout << crr[n] << endl;

    //}

    return 0;
}
