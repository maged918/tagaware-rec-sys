//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a,b,c,d,e,f;

int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(c+e<=a&&max(d,f)<=b)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(c+e<=b&&max(d,f)<=a)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(c+f<=a&&max(d,e)<=b)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(c+f<=b&&max(d,e)<=a)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(d+e<=a&&max(c,f)<=b)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(d+e<=b&&max(c,f)<=a)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(d+f<=a&&max(c,e)<=b)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(d+f<=b&&max(c,e)<=a)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}
