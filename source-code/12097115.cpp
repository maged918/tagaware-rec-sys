//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

long long int A[2][100005];
int B[100005];

int main()
{
    int n,i,a,te,flag=0,ma=0;
    long long int ans=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&B[i]);
        A[0][B[i]]++;
        ma=max(B[i],ma);
    }
    //printf("here");
    for(i=0; i<n; i++)
    {
        te=0;
        a=B[i];
        while(2*a<=ma)
        {
            te++;
            a*=2;
            A[0][a]++;
            A[1][a]+=te;
        }
        a=B[i];
        te=0;
        while(a/2>=1)
        {
            te++;
            if(a%2==1)
            {
                int x=te;
                int p=a/2;
                while(2*p<=ma)
                {
                    x++;
                    p*=2;
                    A[0][p]++;
                    A[1][p]+=x;
                }
            }
            a/=2;
            A[0][a]++;
            A[1][a]+=te;
        }
    }
    //printf("here");
    ans=A[1][1];
    for(i=2; i<=ma; i++)
    {
        if(A[0][i]==n)
        {
            ans=min(A[1][i],ans);
        }
    }
    printf("%I64d",ans);
    return 0;
}
