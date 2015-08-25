//Language: GNU C++


#include <iostream>
using namespace std;
int N,M;
int Array[300005];
void Read()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        char ch;
        cin>>ch;
        if(ch=='.')
            Array[i]=0;
        else
            Array[i]=1;
    }
}

void Solve()
{
    int cont=0,ans=0;
    Array[0]=Array[N+1]=1;
    for(int i=1;i<=N+1;i++)
    {
        if(Array[i]==0)
            ++cont;
        else
            ans+=max(0,cont-1),cont=0;
    }
    for(int i=1;i<=M;i++)
    {
        int poz,val;
        char ch;
        cin>>poz>>ch;
        if(ch=='.')
            val=0;
        else
            val=1;
        if(val==0)
        {
            if(Array[poz]==0)
            {
                cout<<ans<<"\n";
                continue;
            }

            Array[poz]=0;
            if(Array[poz-1]!=Array[poz+1])
                ++ans;
            if(Array[poz-1]==0 && Array[poz+1]==0)
                ans+=2;
        }
        else
        {
            if(Array[poz]==1)
            {
                cout<<ans<<"\n";
                continue;
            }
            Array[poz]=1;
            if(Array[poz-1]!=Array[poz+1])
                --ans;
             if(Array[poz-1]==0 && Array[poz+1]==0)
                ans-=2;
        }
        cout<<ans<<"\n";
    }
}
int main()
{
    Read();
    Solve();
    return 0;
}
