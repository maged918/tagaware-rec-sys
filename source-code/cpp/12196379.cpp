//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string f(string x){
     int l=x.length();
     if(l%2==1) return x;
     string a=f(x.substr(0,l/2));
     string b=f(x.substr(l/2));
     if(a>b) x=b+a; else x=a+b;
     return x;
}

int main(){
    string a,b;
    cin>>a>>b;
    a=f(a);
    b=f(b);
    if(a==b) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    //system("pause");
    return 0;
}
    
