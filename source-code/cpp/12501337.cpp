//Language: GNU C++11


#include<iostream>
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,n,q,o=0,l;
    char c;
    cin>>n>>q>>s;
    for(i=1;i<n;i++)
        if(s[i]==s[i-1] && s[i]=='.')o++;
    for(i=0;i<q;i++)
    {
        cin>>l>>c;
        if(s[l-1]=='.' && c!='.')
        {
            if(l>1)o-=s[l-2]=='.';
            if(l<n)o-=s[l]=='.';
        }
        if(s[l-1]!='.' && c=='.')
        {
            if(l>1)o+=s[l-2]=='.';
            if(l<n)o+=s[l]=='.';
        }
        s[l-1]=c;
        cout<<o<<'\n';
    }
}
