//Language: GNU C++


#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

int n,m,x;
string s;
char c;
set<int>vt;

int main()
{
	
	cin>>n>>m>>s;
	
	for(int i=1;i<n;i++)
	{
		if(s[i]=='.' && s[i-1]=='.')vt.insert(i);
    }
    
	for(int i=1;i<=m;i++)
	{
		cin>>x>>c;
		
		if(c=='.')
		{
                  if(x<n && !vt.count(x) && s[x]=='.')vt.insert(x);
                  if(x>1 && !vt.count(x-1) && s[x-2]=='.')vt.insert(x-1);
        }
        else
        {
                  if(x<n && vt.count(x))vt.erase(x);
                  if(x>1 && vt.count(x-1))vt.erase(x-1);
        }
		
		s[x-1]=c;
		cout<<vt.size()<<endl;
	}
	
	//system("pause");
	return 0;
}
