//Language: MS C++


#include<iostream>
#include<algorithm>
#include<fstream>
#include<utility>
#include<cstring>
#include<string>
#include<vector>
#include<math.h>
#include<cmath>
#include<queue>
#include<map>
#include<set>
using namespace std;

int main()
{
//for(;;)
{
    int n;
    cin>>n;
    map<long long,bool>m;
    long long c=0,cr=0;
    for(int i=0;i<n;i++)
    {
        char ch;long long x;
        cin>>ch>>x;
        if(ch=='+')
            {
                c+=(cr>=c);
                cr++;
                m[x]=1;
            }
        else
            {
                if(m[x])
                    cr--;
                else
                    c++;
                m[x]=0;
            }
    }
    cout<<c<<endl;

}
return 0;
}