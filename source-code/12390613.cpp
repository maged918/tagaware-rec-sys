//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;
const int maxn=1e3;
int a[maxn];
char c[maxn];
const int mi=1e6+100;
int ziad[mi];
main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
        cin>>a[i];
        if(c[i]=='-' && ziad[a[i]]==false)
            cnt++;
        if(c[i]=='+')
            ziad[a[i]]=true;
    }
    int ans=cnt,maxx=cnt;
    for(int i=0;i<n;i++){
        if(c[i]=='-')
            ans--;
        else
            ans++,maxx=max(ans,maxx);
    }
    cout<<maxx<<endl;
    return 0;
}
