//Language: GNU C++


#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

int main()
{
    int n,a[1001];
    cin>>n;
    for(int i = 1; i <= n;i++)
    {
        cin>>a[i];
        if(a[i] == 1)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<1;

    return 0;
}
