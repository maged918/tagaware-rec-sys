//Language: GNU C++


#include<iostream>
#include <cstdlib>
#include<stdio.h>
#include<string.h>

using namespace std;
string s1;
string s2;
string getOrderedStr(string str,int s,int t){
    if((t-s)%2!=0){
        return str.substr(s,t-s);
    }
    string str1=getOrderedStr(str,s,s+(t-s)/2);
    string str2=getOrderedStr(str,s+(t-s)/2,t);
    if(str1<=str2)
        return str1+str2;
    else
        return str2+str1;
}
int main(int argc, char** argv) {
    while(cin>>s1>>s2){
        if(getOrderedStr(s1,0,s1.length())==getOrderedStr(s2,0,s2.length())){
            printf("YES\n");
        }else
            printf("NO\n");
        
    }
    return 0;
}
