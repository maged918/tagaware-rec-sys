//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    int c, d, x, y;
    cin>>a>>b;
    cin>>c>>d>>x>>y;
    if(c+x<=a&&max(d,y)<=b)
    {
        cout<<"YES";
    }
    else if(c+y<=a&&max(d,x)<=b)
    {
        cout<<"YES";
    }
    else if(c+x<=b&&max(d,y)<=a)
    {
        cout<<"YES";
    }
    else if(c+y<=b&&max(d,x)<=a)
    {
        cout<<"YES";
    }
    else if(d+x<=a&&max(c,y)<=b)
    {
        cout<<"YES";
    }
    else if(d+y<=a&&max(c,x)<=b)
    {
        cout<<"YES";
    }
    else if(d+x<=b&&max(c,y)<=a)
    {
        cout<<"YES";
    }
    else if(d+y<=b&&max(c,x)<=a)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    cout<<endl;
    return 0;
}
