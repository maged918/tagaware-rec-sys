//Language: GNU C++


#include<bits//stdc++.h>
using namespace std;
bool check(string str1,string str2)
{
    if(str1==str2)return true;
    else if(str1.size()==2 || str2.size()==2){
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        //cout<<str1<<" "<<str2<<endl;
        if(str1==str2)return true;
        else return false;
    }
    //else if((str1.size()/4)%2!=0) return false;
    else if(str1.size()%2==0){

    string a1=str1.substr(0,str1.size()/2);
    string a2=str1.substr(str1.size()/2,str1.size()-1);
    string b1=str2.substr(0,str2.size()/2);
    string b2=str2.substr(str2.size()/2,str2.size()-1);


    return (check(a1,b2) && check(a2,b1)) || (check(a1,b1) && check(a2,b2));
    }
    else return false;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1==s2)printf("YES\n");
    else if(s1.length()%2!=0)printf("NO\n");
    else{

        if(check(s2,s1))printf("YES\n");
        else printf("NO\n");
    }

}
