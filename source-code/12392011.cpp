//Language: GNU C++11


#include <iostream>

using namespace std;

namespace
{
    struct Pos
    {
        int x;
        int y;
    };

    bool fit(const Pos &board, const Pos &p1, const Pos &p2)
    {
        int ar1[] = {p1.x, p1.y};
        int ar2[] = {p2.x, p2.y};
        for(size_t i = 0; i <= 1; ++i)
        {
            for(size_t j = 0; j <= 1; ++j)
            {
                const auto s1 = ar1[i] + ar2[j];
                const auto s2 = max(ar1[!i], ar2[!j]);
                if(min(s1, s2) <= min(board.x, board.y) &&
                    max(s1, s2) <= max(board.x, board.y))
                    return true;
            }
        }
        return false;
    }
}

int main()
{
    Pos board{0, 0};
    Pos p1{0, 0};
    Pos p2{0, 0};
    cin>>board.x>>board.y;
    cin>>p1.x>>p1.y;
    cin>>p2.x>>p2.y;
    cout<<(fit(board, p1, p2)?"YES":"NO")<<endl;
    return 0;
}
