//Language: GNU C++11


#include<iostream>
#include<conio.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    int n,x,a,cp,cn,count=0;
    cin>>n;
    vector<pair<int,int> >pv,nv;
    for(int i=1;i<=n;i++)
    {
            cin>>x>>a;
            if(x>0)pv.push_back(make_pair(x,a));
            else nv.push_back(make_pair(-x,a));
    }
    sort(pv.begin(),pv.end());
    sort(nv.begin(),nv.end());
    cp=pv.size();cn=nv.size();
    if(cp==cn)
    {
              for(int i=0;i<pv.size();i++)count+=pv[i].second;
              for(int i=0;i<nv.size();i++)count+=nv[i].second;
    }
    else if(cp>cn)
    {
             for(int i=0;i<nv.size();i++)count+=nv[i].second;
             for(int i=0;i<nv.size()+1;i++)count+=pv[i].second;
    }
    else
    {
        for(int i=0;i<pv.size();i++)count+=pv[i].second;
        for(int i=0;i<pv.size()+1;i++)count+=nv[i].second;
    }
    cout<<count;
    //getch();
    return 0;
}
