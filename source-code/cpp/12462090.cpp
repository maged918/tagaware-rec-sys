//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int main()
{
    int n, i;
    bool c= true;
    vector<int> vt;
    cin >> n;
    for(i=0; i<n; i++)
    {
        int v;
        cin >> v;
        if(b[v] == 0 && v<=n)
        {
            b[v]= 44;
            a[i]= v;
        }
    }
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
            vt.push_back(i);
    }
    int k=0;
    for(i=0; i<n; i++)
    {
        if(a[i] == 0 )
        {
            a[i]= vt[k];
            k++;
        }
    }
    for(i=0; i<n; i++)
    {
        if(a[i] == 1)
        {
            c= false;
            break;
        }
    }
    if(c)
      a[0]= 1;
    for(i=0; i<n; i++)
        cout<< a[i]<<" ";
    return 0;
}
