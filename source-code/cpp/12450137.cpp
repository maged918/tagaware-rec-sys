//Language: GNU C++


#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007
#define bl 1
#define wh 0

int main() {
    int n;
    cin >> n;
    
    vi num(n);
    vi sp(100001);
    
    fore(i,0,n)
    {
        cin >> num[i];
        if(sp[num[i]]>0 || num[i]>n)
        {
            num[i]*=-1;
        }
        
        sp[abs(num[i])]++;
    }
    
    vi note;
    
    fores(i,1,n)
    {
        if(sp[i]==0)
        {
            note.pb(i);
        }
    }
    
    int iter = 0;
    
    fore(i,0,n)
    {
        if(num[i]>0)
        {
            cout << num[i] << " ";
        }
        else
        {
            cout << note[iter] << " ";
            iter++;
        }
    }
    
    return 0;
}




