//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;
int a,b;
string s;
int main()
{
    cin>>a>>b>>s;
    int ans=0;
    for(int i=0; i<a-1; i++)
    {
        if(s[i]=='.'&&s[i+1]=='.')ans++;
    }
    for(int i=0; i<b; i++)
    {
        char x;
        int g;
        cin>>g>>x;
        g--;

        if(g!=0&&s[g-1]=='.'&&s[g]=='.'&&x!='.')ans--;
        if(g!=a-1&&s[g+1]=='.'&&s[g]=='.'&&x!='.')ans--;


        if(g!=0&&s[g]!='.'&&s[g-1]=='.'&&x=='.')ans++;
        if(g!=a-1&&s[g+1]=='.'&&s[g]!='.'&&x=='.')ans++;
        s[g]=x;
        cout<< ans << endl;
    }
}
