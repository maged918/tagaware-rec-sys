//Language: GNU C++


#include<bits/stdc++.h>
#define ll long long
//#define pb push_back
#define MAAX 200000
using namespace std;

static vector<int> ar(MAAX) ;
static  vector<int> rech(MAAX);
static vector<int> vst(MAAX);



int main()
{

string s;

    fill(ar.begin(),ar.end(),0) ;

    fill(rech.begin(),rech.end(),0);

    fill(vst.begin(),vst.end(),-1);


int n,t;

    cin>>n;

    queue<pair<int,int> > bfs;



    for(int i=0;i<n;i++)
    {

        cin>>t;


        bfs.push(make_pair(t,0)) ;

        while(!bfs.empty())
        {

            pair<int,int> x=bfs.front();


            bfs.pop() ;

            if(vst[x.first] != i)
            {
                rech[x.first]++;

                ar[x.first]+=x.second;

                vst[x.first]=i;

                bfs.push(make_pair(x.first/2,x.second+1)) ;

                if(x.first*2<200000)
                bfs.push(make_pair(x.first*2,x.second+1)) ;

            }
        }
    }

int ans=INT_MAX ;


    for(int i=1;i<=MAAX;i++)
        if(rech[i]==n)
        {
            ans=min(ans,ar[i]) ;
        }


    cout<<ans;
}
