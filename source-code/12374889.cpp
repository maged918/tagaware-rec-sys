//Language: GNU C++11


#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define mp make_pair
#define iOS ios::sync_with_stdio(false)
using namespace std;
ll n,k,a,m,arr[200005];
set<ll> s;
int main()
{
    iOS;
    cin>>n>>k>>a>>m;
    for(int i=0;i<m;i++)
        cin>>arr[i];
    ll can=n/k;
    s.ins(arr[0]);
    can=(arr[0])/(a+1)+(n-arr[0]+1)/(a+1);
    //cout<<can<<endl;
    if(can<k)
    {
        cout<<1<<endl;
        return 0;
    }
    set<ll>::iterator it,r,l,ch;
    for(int i=1;i<m;i++)
    {
        s.ins(arr[i]);
        ch=s.end();
        ch--;
        it=s.find(arr[i]);
        if(it==s.begin())
        {
            r=++it;
            //cout<<arr[i]<<" "<<*r<<endl;
            can=can-(*r)/(a+1)+(arr[i])/(a+1)+(*r-arr[i])/(a+1);
        }
        else if(++it==s.end())
        {
            --it;
            l=--it;
            //cout<<arr[i]<<" "<<*l<<endl;
            can=can-(n-*l+1)/(a+1)+(arr[i]-*l)/(a+1)+(n-arr[i]+1)/(a+1);
        }
        else
        {
            //cout<<"yolo"<<endl;
            --it;
            r=++it;
            --it;
            l=--it;
            //cout<<arr[i]<<" "<<*l<<" "<<*r<<endl;
            can=can-(*r-*l)/(a+1)+(arr[i]-*l)/(a+1)+(*r-arr[i])/(a+1);
        }
        //cout<<can<<endl;
        if(can<k)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
