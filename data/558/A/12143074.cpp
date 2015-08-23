//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int m[110];
int n;
int main()
{
    while(cin>>n)
    {
        map<int,int>s;
        int i;
        int sum1,sum2,sum3;sum1=sum2=sum3=0;
        for(i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            m[i]=a;
            s[a]=b;
            if(a>0)
                sum2+=b;
            else
                sum3+=b;
            sum1+=b;

        }
        sort(m,m+n);int number=0;
        int flag=0;

        for(i=0;i<n;i++)
        {
            if(m[i]<0&&m[i+1]>0)
            {
                number=i+1;
                flag=1;
            }
        }
        if(flag==0&&m[0]>0)
        {
            cout<<s[m[0]]<<endl;
            continue;
        }
        if(flag==0&&m[0]<0)
        {
            cout<<s[m[n-1]]<<endl;
            continue;
        }
        if(flag==1)
        {
            if(number<n-number)
            {
                int ans=sum3;
                int l;
                for(l=0;l<=number;l++)
                    ans+=s[m[number+l]];
                cout<<ans<<endl;
                continue;
            }
            if(number==n-number)
            {
                cout<<sum1<<endl;
                continue;
            }
            if(number>n-number)
            {
                int ans=sum2;
                int l;
                for(l=0;l<=n-number;l++)
                    ans+=s[m[number-1-l]];
                cout<<ans<<endl;
                continue;

            }
        }
    }
}

 					  	 			 	   			 	 	 	  		