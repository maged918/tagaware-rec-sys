//Language: GNU C++


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int save[6];

int main()
{
    for(int i=0;i<6;i++)cin>>save[i];
    int ans=save[3]+save[3]+1;
  //  cout<<"ans = "<<ans<<endl;
    int last=ans;
    save[2]--;
    save[4]--;
    int l=1,r=1;
    int sum = save[2]+save[1];
    while(sum){
        if(sum==save[1])l=-1,last++;
        if(sum==save[5])r=-1,last++;
        ans+=last+l+r;
        last+=r+l;
        sum--;
        //cout<<"ans = "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
