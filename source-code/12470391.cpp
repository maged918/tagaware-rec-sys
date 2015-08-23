//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    set<string> s;
    set<string>::iterator it;
    cin>>n;
    getline(cin,str);
    int maxv=0;
    for(int i=0;i<n;++i)
    {
        getline(cin,str);
        //cout<<str.substr(2)<<endl;
        if(str[0]=='-' && !s.count(str.substr(2)))
        {
            //s.insert(str.substr(2));
            //if(s.size()>maxv)
            //  maxv=s.size();
            maxv++;
        }
        else if(str[0]=='-' && s.count(str.substr(2)))
        {
            it=s.find(str.substr(2));
            s.erase(it);
            if(s.size()>maxv)
                maxv=s.size();
        }
        else
        {
            s.insert(str.substr(2));
            if(s.size()>maxv)
                maxv=s.size();
        }
    }
    cout<<maxv;
    return 0;
}