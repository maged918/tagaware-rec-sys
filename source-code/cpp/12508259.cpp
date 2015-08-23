//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<n;
    }
    else
    {
        int temp1=m-1;
        int temp2=n-m;
        if(temp1 && temp2)
        {
            if(temp1>=temp2)
            {
            cout<<m-1;
            }
            else
            {
                cout<<m+1;
            }
        }
        else if(temp2)
        {
            cout<<m+1;
        }
        else
        {
            cout<<m-1;
        }
    }
    return 0;
}