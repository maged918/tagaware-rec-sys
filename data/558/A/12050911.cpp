//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <stack>

#define nmax 100005

using namespace std;

struct negApp {
    int position, numApples;
} negApple[nmax];

struct pozApp {
    int position, numApples;
} pozApple[nmax];

int n, numLeft, numRight = 0, poz, rez, apple;

bool cmp1(pozApp a, pozApp b)
{
    return a.position < b.position;
}

bool cmp2(negApp a, negApp b)
{
    return a.position > b.position;
}

int main()
{
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        
        cin >> poz >> apple;
        
        rez += apple;
        
        if (poz < 0)
        {
            numLeft++;
            negApple[numLeft].position = poz;
            negApple[numLeft].numApples = apple;
        }
        else
        {
            numRight++;
            pozApple[numRight].position = poz;
            pozApple[numRight].numApples = apple;
        }
    }
    
    if (numRight > numLeft)
    {
        sort(pozApple+1, pozApple+numRight+1, cmp1);
        for (int i = numRight; i > numLeft + 1; i--)
            rez -= pozApple[i].numApples;
    }
    else if (numLeft > numRight)
    {
        sort(negApple+1, negApple+numLeft+1, cmp2);
        for (int i = numLeft; i > numRight + 1; i--)
            rez -= negApple[i].numApples;
    }
    
    
    cout << rez << "\n";
    
    return 0;
}