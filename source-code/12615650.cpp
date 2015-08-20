//Language: GNU C++11


#include<cstdio>
#include<vector>
using namespace std;
char s[500][501]={{0}};
vector<vector<vector<unsigned> > > a;
const unsigned mod=1000000007;
int n, m;

unsigned solve(const int c=0, const int l=0, const int r=0)
{
    if( a[c][l][r]==0xFFFFFFFF )
    {
        int uu=c-l, ll=l, dd=n-1-c+r, rr=m-1-r;
        
        if( uu>dd || ll>rr )
            return 0;
        else if( s[uu][ll]!=s[dd][rr] )
            a[c][l][r]=0;
        else if( uu==dd && (ll==rr || ll+1==rr) )
            a[c][l][r]=1;
        else if( ll==rr && (uu==dd || uu+1==dd) )
            a[c][l][r]=1;
        else
        {
            int cc=c+1;
            a[c][l][r]=solve(cc, l, r)+solve(cc, l+1, r)+solve(cc, l, r+1)+solve(cc, l+1, r+1);
            a[c][l][r]%=mod;
        }
    }
    
    return a[c][l][r];
}

int main()
{
    for(int i=0; i<500; i++)
        a.push_back(vector<vector<unsigned> >(i+1, vector<unsigned>(i+1, 0xFFFFFFFF)));
    
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%s", s[i]);
    
    printf("%u\n", solve());
}
