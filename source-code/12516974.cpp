//Language: GNU C++


#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int n,m;
    cin>>n>>m;
    int ar[105]={0};
    int k=0;
    for(int i=1;i<=m;i++)
    {
        int max=-1;
        int index=0;
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            if(max<x)
            {
            max=x;
            index=j;
            }
            
        }
        ar[index]++;
    }

    
    int max=-1;
    int index=0;
    for(int i=0;i<105;i++)
    {
    if(ar[i]>max)
    {
    max=ar[i];
    index=i;
    }
    
    }
    if(index==0)
    index=1;
    cout<<index;
    
    return 0;
}