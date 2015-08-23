//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

const int MAX = 105;
int n;
int x, a, sum;
vector <pair <int, int> > l, r; 

bool cmp(pair <int, int> p1, pair <int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
    	l.clear();
	    r.clear();
	    sum = 0;
	    for(int i = 0; i < n; i++)
	    {
	        scanf("%d%d", &x, &a);
	        if(x < 0)
	            l.push_back(make_pair(x, a));
	        else
	            r.push_back(make_pair(x, a));
	        sum += a;
	    }
	    int ls = l.size(), rs = r.size();
	    int total = abs(ls - rs) - 1;
	    sort(l.begin(), l.end(), cmp);
	    sort(r.begin(), r.end(), cmp);
	    if(l.size() > r.size())
	    {
	        for(int i = 0; i < total; i++) 
	            sum -= l[i].second;
	    }
	    else
	    {
	        for(int i = 0; i < total; i++)
	            sum -= r[r.size() - i - 1].second;
	    }
	    printf("%d\n", sum);
    }
    return 0;
}
  		  			 		 	  	 			  			