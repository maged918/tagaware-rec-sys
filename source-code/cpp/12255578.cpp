//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define read() freopen("in.txt","r",stdin)
#define arrsize (ll)1e5+1
#define vul()  prllf("impossible\n");

ll arr[arrsize+1];
ll total[(int)1e6+1];
ll leftt[(int)1e6+1] , rightt[(int)1e6+1];

int main()
{

    int n ;
    while(cin>>n)
    {
        memset(arr,0,sizeof arr);
        memset(total,0,sizeof total);
        memset(rightt,0,sizeof rightt);
        memset(leftt,0,sizeof leftt);
        set<ll> v;

        for( int i =1; i<=n; i++)
        {
            cin>>arr[i];
            v.insert(arr[i]);

            total[arr[i]]++;

            if(leftt[arr[i]]==0)
                leftt[arr[i]]=i;
            rightt[arr[i]]=i;
        }
        ll maxi = INT_MIN, smallx=0, smally=n;
        set<ll> ::iterator it;
        for(  it =v.begin(); it!=v.end(); it++)
        {
            if( maxi<= total[*it])
            {
                maxi = total[*it];
            }
        }
        for(  it =v.begin(); it!=v.end(); it++)
        {
            if(maxi==total[*it])
            {
                ll presentdif = rightt[*it] - leftt[*it];
                //cout<<rightt[*it]<<ends<<leftt[*it]<<ends<<*it<<endl;
                if(presentdif<(smally-smallx))
                {
                    smallx = leftt[*it];
                    smally = rightt[*it];
                    //cout<<smallx<<ends<<smally<<endl;
                }
            }
        }
        cout<<smallx<<" "<<smally<<endl;

    }

}
