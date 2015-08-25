//Language: GNU C++11


/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
2nd Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int
#define all(v) v.begin(),v.end()

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

using namespace std;

double p,q;
int isp[2000010];
int palin[2000010];
int cnt=0;

bool ispalin(int x)
{
    string s;
    while(x)
    {
        s+=(x%10) + '0';
        x/=10;
    }
    for(int i=0,j=s.size()-1;i<=j;i++,j--)
        if(s[i]!=s[j])
            return false;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>p>>q;
    for(int i=1;i<=2e6;i++)
        isp[i]=1;
    isp[1]=0;
    for(int i=2;i<=2e6;i++)
        if(isp[i])
        {
            for(int j=i+i;j<=2e6;j+=i)
                isp[j]=0;
        }
    for(int i=1;i<=2e6;i++)
        if(ispalin(i))
            palin[i]=1;

    for(int i=2;i<=2e6;i++)
        palin[i]+=palin[i-1];
    for(int i=2;i<=2e6;i++)
        isp[i]+=isp[i-1];

    //for(int i=1;i<=200;i++)
    //    cout<<i<<" "<<(double)isp[i]/palin[i]<<"\n";

    int ans=-1;
    double asdads=p/q;
    //cout<<asdads<<"\n";
    for(int i=1;i<=2e6;i++)
        if(asdads - ((double)isp[i]/palin[i]) >-EPS )
               ans=i;
    if(ans==-1)
        cout<<"Palindromic tree is better than splay tree";
    else
        cout<<ans;

    return 0;
}
