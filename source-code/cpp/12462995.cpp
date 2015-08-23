//Language: GNU C++11


#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

int p, q;
bool isPrime[1400000];
bool isPalim[1400000];

bool Palim(int num)
{
    int comp = 0, temp = num;
    while(temp)
    {
        comp *= 10;
        comp += temp % 10;
        temp /= 10;
    }
    return comp == num;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    memset(isPrime, true, sizeof(isPrime));
    memset(isPalim, true, sizeof(isPalim));
    isPrime[1] = false;
    for(int i = 2; i <= 1300000; i++)
    {
        if(!isPrime[i]) continue;
        for(int j = i+i; j <= 1300000; j += i)
            isPrime[j] = false;     
    }
    for(int i = 1; i <= 1300000; i++)
        isPalim[i] = Palim(i);
    
    scanf("%d%d", &p, &q);
    int res = 0;
    int primec = 0, palimc = 0;
    for(int i = 1; i <= 1300000; i++)
    {
        if(isPrime[i])
            primec++;
        if(isPalim[i])
            palimc++;

        if(q * primec <= p * palimc)
            res = i;
    }
    if(res == 0)
        puts("Palindromic tree is better than splay tree");
    else
        printf("%d\n", res);
}