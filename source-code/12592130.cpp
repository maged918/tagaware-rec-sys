//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;

#define mod 1000000007

lol m,n;
string str[505];
lol dp[2][506][506]={{{0}}};


bool ok(lol r1,lol c1,lol r2,lol c2);


void trell()
{
    for(int i=0;i<=(n+m-2)/2;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                cout<<dp[i][j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}


int main()
{
    //ifstream fin;
    //fin.open("output.txt");
    //#define cin fin
    cin>>m>>n;
    for(lol i=0;i<m;i++)
    {
        cin>>str[i];
    }

    dp[1][0][m-1]=1;

    for(lol moves=0;moves<((n+m-2)/2);moves++)
    {
        for(lol i=0;i<m;i++) for(lol j=0;j<m;j++) dp[0][i][j]=dp[1][i][j],dp[1][i][j]=0;
        for(lol r1=0;r1<m;r1++)
        {
            for(lol r2=0;r2<m;r2++)
            {
                lol c1 = moves - r1;
                lol c2 = -r2 + n + m - moves - 2;

                if(!ok(r1,c1,r2,c2)) continue;       // boundary ke bahar hai
                if(str[r1][c1]!=str[r2][c2]) continue;

                lol yahan_tak=dp[0][r1][r2];    // ye thora ajeeb wala dp hai

                // the 4 possible cases

                if(ok(r1+1,c1,r2,c2-1) && str[r1+1][c1]==str[r2][c2-1]) dp[1][r1+1][r2]   =   (dp[1][r1+1][r2] + yahan_tak)%mod;
                if(ok(r1+1,c1,r2-1,c2) && str[r1+1][c1]==str[r2-1][c2]) dp[1][r1+1][r2-1] =   (dp[1][r1+1][r2-1] + yahan_tak)%mod;
                if(ok(r1,c1+1,r2-1,c2) && str[r1][c1+1]==str[r2-1][c2]) dp[1][r1][r2-1]   =   (dp[1][r1][r2-1] + yahan_tak)%mod;
                if(ok(r1,c1+1,r2,c2-1) && str[r1][c1+1]==str[r2][c2-1]) dp[1][r1][r2]     =   (dp[1][r1][r2] + yahan_tak)%mod;
            }
        }
    }

    //trell();

    int ans=0;

    for(lol i=0;i<m;i++)
    {
        for(lol j=0;j<m;j++)
        {
            ans=(ans+dp[1][i][j])%mod;
        }
    }
    cout<<ans;
    return 0;
}


bool ok(lol r1,lol c1,lol r2,lol c2)
{
    if(r1>=0 && r2<m && c1>=0 && c2<n && r1<m && r2>=0 && c1<n && c2>=0 && r1<=r2 && c1<=c2) return true;
    return false;
}
