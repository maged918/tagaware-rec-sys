//Language: GNU C++


#include<iostream>

using namespace std;

int main()
{
    int x,y,a,b,c,d;
    cin>>x>>y>>a>>b>>c>>d;
    if ((a+c<=x&&b<=y&&d<=y)||(a+c<=y&&b<=x&&d<=x)||(a+d<=x&&b<=y&&c<=y)||(a+d<=y&&b<=x&&c<=x)||(b+c<=x&&a<=y&&d<=y)||(b+c<=y&&a<=x&&d<=x)||(b+d<=x&&a<=y&&c<=y)||(b+d<=y&&a<=x&&c<=x))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}