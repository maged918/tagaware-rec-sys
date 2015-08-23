//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int ans=0;
    for(int f=0;f+1<n;f++)
    {
        if(isalpha(s[f]))
            s[f]='a';
        ans+=(s[f]=='.'&&s[f+1]=='.');
    }
    int i;
    char c;
    for(int f=0;f<m;f++)
    {
        cin>>i>>c;
        i--;
        if(isalpha(c))
            c='a';
        if(s[i]==c)
            cout<<ans<<endl;
        else if(c=='.')
        {
            if(i&&s[i-1]=='.')
                ans++;
            if(i+1<n&&s[i+1]=='.')
                ans++;
            cout<<ans<<endl;
        }
        else
        {
            if(i&&s[i-1]=='.')
                ans--;
            if(i+1<n&&s[i+1]=='.')
                ans--;
            cout<<ans<<endl;
        }
        s[i]=c;
    }
}
