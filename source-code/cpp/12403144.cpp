//Language: GNU C++


#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
set<int> ss;
set<int>::iterator it;
int main() {
    int n,k,a;
    cin>>n>>k>>a;
    ss.clear();
    ss.insert(0);
    ss.insert(n+1);
    int m;
    cin>>m;
    int now=(n+1)/(a+1);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        if (ss.find(x)==ss.end())
        {
            ss.insert(x);
            it=ss.upper_bound(x);
            int r=*it;
            it=ss.lower_bound(x);
            it--;
            int l=*it;
            now-=(r-l)/(a+1);
            now+=(x-l)/(a+1);
            now+=(r-x)/(a+1);
            if (now<k)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}