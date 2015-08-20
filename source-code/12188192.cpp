//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <map>
#include <string.h>

using namespace std;

#define HASHES 1
typedef long long ll;

ll MO[] = {1000000007, 1000000009, 1000000007};
ll PR[] = {137, 173, 17};
ll PO[HASHES][200005];
ll HA[HASHES][200005][2];

string a, b;

void init(){

    PO[0][0] = 1;

    for(int h = 0; h < HASHES; ++h){
        for(int i = 0; i < a.size(); ++i){

            if(i)
                PO[h][i] =  (PO[h][i-1] * PR[h]) % MO[h];

            if(i){
                HA[h][i][0] = ((HA[h][i-1][0] * PR[h]) + a[i]) % MO[h];
                HA[h][i][1] = ((HA[h][i-1][1] * PR[h]) + b[i]) % MO[h];
            }else{
                HA[h][i][0] = a[i] ;
                HA[h][i][1] = b[i] ;
            }
           // cout << i << " = " << HA[h][i][k] << endl;

        }
    }
}

ll getHash(int hId, int l,int r, int k){
    ll ret = HA[hId][r][k];

    if(l == 0)return ret;
    ret = (ret - (HA[hId][l-1][k]*PO[hId][(r-l+1)])) % MO[hId];
    ret = (ret + MO[hId])%MO[hId];
    return ret;
}

bool same (int l, int r, int l2, int r2){

    for(int i = 0; i < HASHES; i++){


        if(getHash(i, l, r, 0) != getHash(i, l2, r2, 1))
            return false;
    }

    return true;
}

bool solve(int a1, int a2, int b1, int b2){


    if( same(a1, a2, b1, b2) )
        return true;

    if( (a2 - a1 + 1) & 1)
        return false;


    int midpoint_a = (a2 + a1) / 2;
    int midpoint_b = (b2 + b1) / 2;

    bool ans = ( solve( a1, midpoint_a, midpoint_b + 1, b2) && solve( midpoint_a + 1, a2, b1, midpoint_b ));

    if(!ans)
        ans = ans ||  ( solve( a1, midpoint_a, b1, midpoint_b ) && solve( midpoint_a + 1, a2, midpoint_b + 1, b2)  );

    return ans;

}

int main()
{

  cin >> a;
  cin >> b;

    init();

    if ( solve( 0, a.size() - 1, 0, b.size() - 1)  )
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}