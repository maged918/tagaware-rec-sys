//Language: GNU C++11


#include <iostream>
#include <stack>

using namespace std;

void solve(unsigned int arr[],unsigned int n)
{
    ios_base::sync_with_stdio(false);
    unsigned int hash[n+1];
    fill_n(hash,n+1,0);
    stack <unsigned int> st;
    for(auto i = 0;i < n;i++)
        if(arr[i] && arr[i] <= n)
            hash[arr[i]]++;
    for(auto i = 1;i <= n;i++)
        if(!hash[i])
            st.push(i);
    for(auto i = 0;i < n;i++)
    {
        if(arr[i] && arr[i] <= n)
            hash[arr[i]]--;
        if((arr[i] && arr[i] >n) || hash[arr[i]] >= 1)
        {
           arr[i] = st.top();
           st.pop();
        }
   }
    for(auto i = 0;i < n;i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned int n;
    cin >> n;
    unsigned int arr[n];
    for(auto i = 0;i < n;i++)
        cin >> arr[i];
    solve(arr,n);
    return 0;
}
