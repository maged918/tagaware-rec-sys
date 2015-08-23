//Language: MS C++


#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int n,m;

string s;

int main()
{
    cin >> n >> m >> s;

    int i,cnt;
    int idx;
    string q;
    cnt=0;
    for(i=0; i<n; ++i)
    {
        if(s[i] != '.')
            continue;
        ++i;
        while(i<n && s[i]=='.')
        {
            ++cnt;
            ++i;
        }
    }
    while(m--)
    {
        cin >> i >> q;
        --i;
        if(q==".")
        {
            if(s[i] != '.')
            {
                if(i>0 && s[i-1]=='.')
                    ++cnt;
                if(i<n-1 && s[i+1]=='.')
                    ++cnt;
                s[i]='.';
            }
        }
        else
        {
            if(s[i]=='.')
            {
                if(i>0 && s[i-1]=='.')
                    --cnt;
                if(i<n-1 && s[i+1]=='.')
                    --cnt;
                s[i]='a';
            }
        }
        printf("%d\n",cnt);
        //cnt=0;
    }
    return 0;
}