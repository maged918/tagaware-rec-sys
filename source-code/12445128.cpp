//Language: GNU C++


#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define vii vector<int> :: iterator
#define vli vector<ll> :: iterator
#define miii map<int,int> :: iterator 
#define mlli map<ll,ll> :: iterator
#define mm(a,b) memset(a,b,sizeof(a)) 
#define f_i(a,b) fill(a.begin(),a.end(),b)
#define pp pair<ll,ll> 
#define mp make_pair

using namespace std;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0) ;

      #ifndef ONLINE_JUDGE
        freopen("INPUT.txt", "r", stdin);
      #endif      



        set<int> yes;

        int a[100001] ;
        bool done[100001] ;

        mm(done,false) ;

        int n;
            cin>>n;

        for(int i=1;i<=n;i++)
            yes.insert(i) ;



        mm(a,-1) ;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            if(yes.count(a[i]))
            {
                yes.erase(a[i]) ;
                done[i]=true;
            }
        }


        for(int i=0;i<n;i++)
        {
            if(!done[i])
            {
                set<int> :: iterator y=yes.begin();
                cout<<*y<<" ";
                yes.erase(*y) ;

            }
            else
                cout<<a[i]<<" ";
        }

}   
