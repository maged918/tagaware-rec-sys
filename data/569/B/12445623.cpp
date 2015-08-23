//Language: MS C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <utility>
#include <iomanip>
#include <set>
#include <numeric>
#include <ctime>
 
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
#define PI acos(-1.0)
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second

 
using namespace std;

bool chk [100001];
bool zam [100000];

int elm [100000];
vector <int> result;
int main()
{
    int n , x, k=1; 
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>elm[i];
    /*  if (x <= n)
        {
            if (!chk[x])
            {
                result.push_back(x);
                chk[x]= true;
                if (x == k)
                    while (chk[k])
                    k++;
            }
            else
            {
                if(chk[k])
                    while (chk[k])
                        k++;

                result.push_back(k);
                chk[k]= true;
                while (chk[k])
                    k++;
            }
        }
        else
        {
            if(chk[k])
                    while (chk[k])
                        k++;
            result.push_back(k);
            chk[k]= true;
            while (chk[k])
            k++;
        }*/
    }
    for (int i=0; i<n; i++) //ищем чьи номера менять  не нужно
    {
        if(elm[i] <=n && !chk[elm[i]])
            {
                zam[i]= true; // менять не надо
                chk[elm[i]]=true;
            }

    }

    for (int i=0; i<n; i++)
    {
        if(zam[i])
            result.push_back(elm[i]);
        else
        {
            if(chk[k])
                    while (chk[k])
                        k++;
            result.push_back(k);
            chk[k]= true;
            while (chk[k])
                k++;
        }

    }


    for( int i=0; i<n; i++)
        {
            cout<<result[i]<<" ";
        }

return 0;
}