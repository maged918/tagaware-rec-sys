//Language: GNU C++


#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n],mini[n],maxi[n];
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    mini[0]=fabs(arr[0]-(arr[1]));
    maxi[0]=fabs(arr[0]-(arr[n-1]));
    mini[n-1]=fabs(arr[n-1]-(arr[n-2]));
    maxi[n-1]=fabs(arr[n-1]-(arr[0]));
    for(int i=1 ; i<n-1 ; i++)
    {
        if(fabs(arr[i]-(arr[i-1]))>fabs(arr[i]-(arr[i+1])))
        {
            mini[i]=fabs(arr[i]-(arr[i+1]));
        }
        else
        {
            mini[i]=fabs(arr[i]-(arr[i-1]));
        }
        if(fabs(arr[i]-(arr[0]))>fabs(arr[i]-(arr[n-1])))
        {
            maxi[i]=fabs(arr[i]-(arr[0]));
        }
        else
        {
            maxi[i]=fabs(arr[i]-(arr[n-1]));
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        cout << mini[i] << " " << maxi[i] << endl ;
    }
    return 0;
}
