//Language: GNU C++


#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
using namespace std;
#define mod 1000000007

long long n,m,i,j,max_votes,winner;
int main()
{
    cin>>n>>m;
    vector< vector<long long> > data(m,vector<long long>(n));
    vector<long long> record(n,0);
    for(i=0;i<m;i++)
    {
        max_votes=-1;
        for(j=0;j<n;j++)
        {
            cin>>data[i][j];
            if(data[i][j]>max_votes)
            {
                max_votes=data[i][j];
                winner=j;
            }
        }
        record[winner]++;
    }
    max_votes=-1;
    for(i=0;i<n;i++)
    {
        //cout<<record[i]<<" ";
        if(record[i]>max_votes)
        {
            max_votes=record[i];
            winner=i;
        }
    }
    cout<<winner+1;
}