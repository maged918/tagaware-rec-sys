//Language: GNU C++


#include <iostream>
#include<fstream>
#include<cstdlib>

using namespace std;
   // ifstream fcin("a.in");

int main()
{   int n, i;
    int a[100002];

    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];

    cout<<abs(a[1]-a[2])<<" "<<abs(a[n]-a[1])<<"\n";

    for(i=2; i<n; i++)
       { cout<<min(abs(a[i]-a[i-1]), abs(a[i+1]-a[i]))<<" ";
        cout<<max(abs(a[i]-a[1]), abs(a[n]-a[i]));
        cout<<"\n";}

    cout<<abs(a[n]-a[n-1])<<" "<<abs(a[n]-a[1]);

    return 0;

}
