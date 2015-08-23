//Language: GNU C++


#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int idx , idx2;
pair < long long , long long > A[100050] , B[100050];

int main()
{
    int h , q;
    scanf("%d%d" , &h , &q);

    bool f = false;
    long long l = (1LL << (h - 1)) , r = (1LL << h) - 1;
    for(int i = 0;i < q;++i)
    {
        long long lvl , L , R , k;
        scanf("%I64d %I64d %I64d %I64d" , &lvl , &L , &R , &k);

        for(int i = lvl;i < h;++i)
        {
            L <<= 1;
            R <<= 1;
            ++R;
        }
        if(k)
        {
            f = true;
            if(r < L or l > R)
            {
                printf("Game cheated!");
                return 0;
            }
            l = max(l , L);
            r = min(r , R);
        }
        else
            A[idx++] = make_pair(L , R);

        if(l > r)
        {
            printf("Game cheated!");
            return 0;
        }
    }
    if(idx)
    {
        sort(A , A + idx);
        long long l2 = (1LL << (h - 1)) , r2 = (1LL << h) - 1 , st = A[0].first , en = A[0].second;
        if(A[0].first > l2)
            B[idx2++] = make_pair(l2 , A[0].first - 1);

        for(int i = 1;i < idx;++i)
        {
            if(A[i].first > en + 1)
            {
                B[idx2++] = make_pair(en + 1 , A[i].first - 1);
                st = A[i].first;
                en = A[i].second;
            }
            else
                en = max(en , A[i].second);
        }
        if(en < r2)
            B[idx2++] = make_pair(en + 1 , r2);

        if(!f)
        {
            if(!idx2)       printf("Game cheated!");
            else if(idx2 > 1 or (idx2 == 1 and B[0].first != B[0].second))    printf("Data not sufficient!");
            else            printf("%I64d" , B[0].first);

            return 0;
        }

        long long z1 = l , z2 = r;
        bool flag = false;
        for(int i = 0;i < idx2;++i)
        {
            if(B[i].first > z2)
                break;

            if(B[i].second < z1)
                continue;

            if(flag)
            {
                printf("Data not sufficient!");
                return 0;
            }
            flag = true;
            l = max(l , B[i].first);
            r = min(r , B[i].second);

        }
        if(!flag)
        {
            printf("Game cheated!");
            return 0;
        }
    }

    if(l != r)
        printf("Data not sufficient!");
    else
        printf("%I64d" , l);

    return 0;
}
/*4 3
1 1 1 1
4 8 10 0
4 12 14 0
*/
