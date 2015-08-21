//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX = 200100;
char str1[MAX],str2[MAX];
int solve(char *a,char *b,int len)// a1 b1 a2 b2
{
    if(len&1)
    {
        for(int i = 0;i < len;i ++)
        {
            if(a[i] != b[i])
                return 0;
        }
        return 1;
    }
    int bin_len = len / 2;
    if(solve(a,b+bin_len,bin_len) && solve(a+bin_len,b,bin_len)) //a1=b2 && a2=b1
            return 1;
    if(solve(a,b,bin_len) && solve(a+bin_len,b+bin_len,bin_len))//a1=b1 && a2=b2
            return 1;
    return 0;
}
int main()
{
    while(cin>>str1>>str2)
    {
        int len = strlen(str1);
        int ans = solve(str1,str2,len);
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
