//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

const long long ONE = 1;

vector< pair<long long, long long> > dead; 



int main()
{
    int h, q;
    int level, ans;
    long long qL, qR;
    long long L, R;
    
    
    cin >> h >> q;
    
    L = (ONE<<(h-1));
    R = (ONE<<h)-1;
    
    for(int i = 1; i <= q; i++)
    {
        cin >> level >> qL >> qR >> ans;
        
        qL = qL*(ONE<<(h-level));
        qR = (qR+1)*(ONE<<(h-level))-1;
        // 2 5 11    2^2 * 2 + 2^1 + 1  =  2^2 * 2 + 1(2^2-1) / (2-1)  =  2^2 * (2+1) - 1 
        // 2^n * (x+1) - 1
        
        if(ans == 0)
        {
            dead.push_back(make_pair(qL, qR));
        }
        else
        {
            dead.push_back(make_pair(L, qL-1));
            dead.push_back(make_pair(qR+1, R));
        }
    }
    
    dead.push_back(make_pair(L-1, L-1));
    dead.push_back(make_pair(R+1, R+1)); // for easy to implentation
    sort(dead.begin(), dead.end());
    
    long long x, index;
    long long exits;
    
    x = L;
    exits = 0;
    for(int k = 0; k < dead.size(); k++)
    {
        long long left = dead[k].first, right = dead[k].second;
        if(left > right) continue;
        
        if(left >= x+1)
        {
            index = x;
            exits += left-x;
        }
        
        x = max(x, right+1);
    }
    
    if(exits == 0)
    {
        cout << "Game cheated!" << endl;
    }
    else if(exits == 1)
    {
        cout << index << endl;
    }
    else if(exits > 1)
    {
        cout << "Data not sufficient!" << endl;
    }
}
