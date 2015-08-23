//Language: GNU C++11


#include <iostream>
#include <algorithm>

using namespace std;

struct tree {
    int pos;
    int num;
};

bool cmp(tree &p, tree &q)
{
    return p.pos < q.pos;
}

int main()
{
    int N;
    cin >> N;

    tree t[101];
    t[0].pos = 0;
    t[0].num = 0;
    for(int i=1; i <= N; i++)
        cin >> t[i].pos >> t[i].num;

    ++N;
    sort(t, t + N, cmp);

    int zero_pos=0;
    while(t[zero_pos].pos != 0)
        zero_pos++;

    int lret = 0;
    int pos = zero_pos;

    int left=pos, right=pos;
    int turn = 0;
    while(1)
    {
        if(turn == 0)
        {
            //left
            --left;
            if(left < 0)
                break;
            lret += t[left].num;
        }
        else
        {
            ++right;
            if(right >= N)
                break;
            lret += t[right].num;
        }
        turn = !turn;
    }

    int rret = 0;

    pos = zero_pos;
    left = right = pos;
    turn = 1;

    while(1)
    {
        if(turn == 0)
        {
            //left
            --left;
            if(left < 0)
                break;
            rret += t[left].num;
        }
        else
        {
            ++right;
            if(right >= N)
                break;
            rret += t[right].num;
        }
        turn = !turn;
    }

    cout << max(lret,rret);

    return 0;
}