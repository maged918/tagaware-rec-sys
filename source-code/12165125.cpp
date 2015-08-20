//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <utility>
#include <stack>
#include <list>
#include <queue>
using namespace std;

int main() {
    // your code goes here
    int n,i;
    cin>>n;
    long arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    if(arr[0]==1)
    cout<<"-1";
    else
    cout<<"1";
    return 0;
}