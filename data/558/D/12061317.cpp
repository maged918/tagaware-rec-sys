//Language: GNU C++11


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int N, Q;
set<pair<long long, long long> > S;

int main()
{
    cin.sync_with_stdio(false);
    
    cin >> N >> Q;
    
    S.insert(make_pair((1LL << (N - 1)), (1LL << N) - 1));
    for (int i = 1; i <= Q; ++i)
    {
        int lv;
        long long L, R, ans;
        
        cin >> lv >> L >> R >> ans;
        
        L <<= (N - lv);
        R <<= (N - lv);
        R += (1LL << (N - lv)) - 1;
        
        if (ans == 1)
        {
            auto beg = S.begin();
            while (beg->first < L)
            {
                if (beg->second >= L)
                    S.insert(make_pair(L, beg->second));
                S.erase(beg);
                
                if (S.empty()) break;
                
                beg = S.begin();
            }
            
            if (S.empty()) break;
            
            auto end = S.end();
            --end;
            while (end->second > R)
            {
                if (end->first <= R)
                    S.insert(make_pair(end->first, R));
                S.erase(end);
                
                if (S.empty()) break;
                
                end = S.end();
                --end;
            }

            if (S.empty()) break;
        }
        else
        {
            auto now = S.lower_bound(make_pair(L, 0));
            if (now != S.begin())
            {
                --now;
                if (now->second >= L)
                {
                    S.insert(make_pair(now->first, L - 1));
                    if (now->second > R)
                        S.insert(make_pair(R + 1, now->second));
                    S.erase(now);
                }
            }
            
            if (S.empty()) break;
            
            while (true)
            {
                now = S.lower_bound(make_pair(L, 0));
                
                if (now == S.end() || now->first > R)
                    break;
                if (now->second > R)
                {
                    S.insert(make_pair(R + 1, now->second));
                    S.erase(now);
                    break;
                }
                S.erase(now);
                
                if (S.empty()) break;
            }
            
            if (S.empty()) break;
        }
    }

    if (S.empty()) cout << "Game cheated!\n";
    else if (S.size() == 1 && S.begin()->first == S.begin()->second) cout << S.begin()->first << '\n';
    else cout << "Data not sufficient!\n";
}
