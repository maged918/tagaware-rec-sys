//Language: GNU C++11


#include<bits/stdc++.h>

using namespace std;

string smallest(string s) {
    if (s.size() % 2 == 1) return s;
    string s1 = smallest(s.substr(0, s.size()/2));
    string s2 = smallest(s.substr(s.size()/2, s.size()));
    if (s1 < s2) return s1 + s2;
    else return s2 + s1;
}

main()
{
    string a,b;
    cin>>a>>b;
    a=smallest(a);
    b=smallest(b);
    if(a==b)
        cout<<"YES";
    else
        cout<<"NO";
}

