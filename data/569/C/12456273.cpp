//Language: GNU C++


#include<bits/stdc++.h>
//Definitions
#define LL long long
#define LLU unsigned long long
#define fora(var,end) for(int var=0;var<end;var++)
#define fore(var,start,end) for(int var=start;var<end;var++)
#define forit(it1,a) for(typeof(a.begin()) it1=a.begin();it1!=a.end();it1++)
#define pub push_back
#define fst first
#define snd second
#define MOD 1000000007
#define mkp make_pair
#define beg begin
#define ed end
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define P(a,b) cout<<a<<" "<<b<<" "
#define PNL printf("\n")
#define vi vector<int>
#define vpi vector<pair<pair<int,int>,int> >
#define FL(a,n,x) fill(a,a+n,x)
//AP_HAWKDOWN from hereon
using namespace std;
bool seive[10000000];
int pal(int i)
{
    vector<int> v;
    while(i>0)
    {
        v.pub(i%10);
        i/=10;
    }
    int sz=v.size();
    fora(j,sz/2)
    {
        if(v[j]!=v[sz-1-j])
        {
            return 0;
        }
    }
    return 1;

}
int main()
{

LL p,q;

cin>>p>>q;
for(int i=2;i*i<3000000;i++)
{

    if(!seive[i]){
     //       ct++;
    for(int j=2;i*j<3000000;j++)
    {
     seive[i*j]=true;
    }
    }
}

int counter=0;
LL ct=0,ans,x=0;

seive[1]=true;
int flag=0;
fore(i,1,2000000)
{
    if(!seive[i])
    {
        //cout<<"Prime"<<" "<<i<<endl;
    ct++;
    }
    if(pal(i))
    {
        //cout<<"pal "<<i<<endl;
        x++;
    }

    if(q*ct<=p*x)
    {
        flag=1;
        ans=i;
    }
}
//cout<<ct<<endl<<x<<endl;
if(flag==1)
cout<<ans;
else
{
    cout<<"Palindromic tree is better than splay tree\n";
}

return 0;
}