//Language: GNU C++


#include<iostream>
#include<set>
using namespace std;
const int M=1e5+10;
int arr[M],mark[M],p=1;
set<int>s;
int main()
{
    ios::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        s.insert(i);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        s.erase(arr[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!mark[arr[i]] && arr[i]<=n)
            mark[arr[i]]=true;
        else
        {
            arr[i]=*s.begin();
            s.erase(*s.begin());
            mark[*s.begin()]=true;
        }
        cout<<arr[i]<<" ";
    }
    return 0;
}