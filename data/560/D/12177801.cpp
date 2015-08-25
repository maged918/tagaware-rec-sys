//Language: GNU C++


#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s,t;
int f(int is,int js,int it,int jt)
{
    int lop=0;
    for(int k=0;k<=js-is;k++)
    {
        if(s[is+k]==t[it+k])
        continue;
        lop=1;
        break;
    }
    if(lop==0)
    return 1;
    if((js-is)%2==0)
    return 0;
  //  cout<<is<<" "<<(js-((js-is)/2))-1<<endl;
    if(((f(is,is+((js-is)/2),(it+(jt-it)/2)+1,jt))&&(f((is+(js-is)/2)+1,js,it,it+((jt-it)/2)))))
    {
        return 1;
    }
    if(f(is,is+((js-is)/2),it,it+((jt-it)/2))&&f((is+(js-is)/2)+1,js,(it+(jt-it)/2)+1,jt))
    return 1;
    return 0;
}
int main()
{
    cin>>s>>t;
//  cout<<s.size()<<endl;
    if(f(0,s.size()-1,0,t.size()-1))
    cout<<"YES";
    else
    cout<<"NO";
}