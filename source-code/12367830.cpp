//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define Max 1000005

lli n,k,a[Max];
lli p[1][8000000],ans,r12[8000000];

map<lli,lli>mp;

int main()
{
    lli m=0,t0,t1,t2;
        cin>>n>>k;
        for(lli i=1; i<=n; i++)
        {
            cin>>a[i];
        }

        for(lli i=1; i<=n; i++)
        {

            if(a[i]%(k*k)==0){
                t2=a[i]/(k*k);
                if(mp.find(t2)==mp.end())
                {
                    mp[t2]=m++;
                }
                //r23[mp[t2]] = r12[mp[t2]]*p[2][mp[t2]];
                ans += r12[mp[t2]];
            }
            if(a[i]%k==0){
                t1=a[i]/k;
                if(mp.find(t1)==mp.end())
                {
                    mp[t1]=m++;
                }
                r12[mp[t1]] += p[0][mp[t1]];
            }
            
            t0=a[i];
            if(mp.find(t0)==mp.end())
            {
                mp[t0]=m++;
            }
            p[0][mp[t0]]++;
        
            

        }
        cout<<ans<<'\n';

        return 0;
}
