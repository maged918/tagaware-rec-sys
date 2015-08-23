//Language: GNU C++11


#include <iostream>
#include <vector>
using namespace std;

vector <int> towns;
int n, m;
int procTown()
{
    vector <int> v;
    int t;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] > v[mx]) mx = i;
    }

    towns[mx]++;
}



int main()
{
    cin >> n >> m;
    towns.resize(n, 0);
    for(int i = 0; i < m; i++)
    {
        procTown();
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        if(towns[i] > towns[mx]) mx = i;
    }

    cout << mx+1;
    return 0;
}
