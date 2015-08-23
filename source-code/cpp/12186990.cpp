//Language: GNU C++


#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
        if(arr[i]==1)
        {
            cout << "-1" << endl ;
            return 0;
        }
    }
    cout << "1" << endl ;
    return 0;
}
