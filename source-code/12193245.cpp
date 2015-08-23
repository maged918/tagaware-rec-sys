//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,x,y,xx,yy; cin>>a>>b>>x>>y>>xx>>yy;
    if (x>y) swap(x,y);
    if (xx>yy) swap(xx,yy);
    int ch=0;
    if (x+xx<=a&&max(y,yy)<=b) ch=1;
    if (y+yy<=a&&max(x,xx)<=b) ch=1;
    if (y+yy<=b&&max(x,xx)<=a) ch=1;
    if (x+xx<=b&&max(y,yy)<=a) ch=1;
    if (x+yy<=a&&max(y,xx)<=b) ch=1;
    if (xx+y<=a&&max(yy,x)<=b) ch=1;
    if (x+y<=a&&max(xx,yy)<=b) ch=1;
    if (xx+yy<=a&&max(x,y)<=b) ch=1;
    if (ch) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
