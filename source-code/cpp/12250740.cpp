//Language: MS C++


#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>
#include<set>
#include<stack>
#include<queue>
#include<fstream>
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define repd(i,m,n) for(ll i=(m); i > (n); i--)
#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define endl '\n'
#define x first
#define y second
using namespace std;
const ll modd = 1000*1000*1000 + 7;
struct info{
    int l,r,number;
    info(){}
    info(int l1,int r1,int number1)
    {
        l = l1, r = r1, number = number1;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int,info> mapp;
    int n,x;
    cin >> n;
    rep(i,0,n)
    {
        cin >> x;
        if (mapp.find(x) == mapp.end())
        {
            mapp[x] = info(i,i,1);
        }else
        {
            mapp[x].number++;
            mapp[x].r = i;
        }
    }
    int coun = 0, l = 0, r = 0;


    for (auto i = mapp.begin(); i != mapp.end(); i++)
    {
        if (i -> second.number > coun)
        {
            coun = i -> second.number;
            l = i -> second.l;
            r = i -> second.r;
        }

        if (i -> second.number == coun)
        {
            if (r - l > i -> second.r - i -> second.l)
            {
                r = i -> second.r;
                l = i -> second.l;
            }
        }
    }
    cout << l + 1 << " " << r + 1 << endl;
    return 0;
}