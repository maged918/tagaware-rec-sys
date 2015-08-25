//Language: GNU C++


#include <iostream>
#include <cstring>
using namespace std;

struct Requeriment{
    int l;
    int r;
    string sign;
} reqs[200];

typedef long long ll;
ll dp[205][205];
int n, k;

int previously_placed( int l, int r){

    int tot = 2 * n  - (r - l + 1);

    tot /= 2;

    return tot;
}

int get_estado(int pos, int l, int r, int x, int y){


    if(pos < l || pos > r)
        return -1;

    if(pos == x || pos == y)
        return 0;

    return 1;
}


bool ok (int estado_l, int estado_r, int id){

    string sign = reqs[id].sign;

    if(sign == "=")
        return estado_l == estado_r;

    if(sign == ">=")
        return (estado_l >= estado_r);

    if(sign == ">")
        return (estado_l > estado_r);

    if(sign == "<")
        return (estado_l < estado_r);

    if(sign == "<=")
        return (estado_l <= estado_r);

}
bool is_valid(int l, int r, int pos1, int pos2){



    for(int i = 0; i < k; i++){

        int estado_l = get_estado( reqs[i].l, l, r, pos1, pos2);
        int estado_r = get_estado( reqs[i].r, l, r, pos1, pos2);


        if( estado_l && estado_r) continue;

       // if( reqs[i].l == pos1 || reqs[i].l == pos2 || reqs[i].r == pos1 || reqs[i].r == pos2){
        if( !ok(estado_l, estado_r, i) ){

            return false;
        }
      //  }
    }

    return true;
}


ll solve(int left, int right){


    if( right - left + 1 <= 2) {
        return is_valid(left, right, left, right);
    }

    if(dp[left][right] != -1) return dp[left][right];

    ll ans = 0;

    if( is_valid(left, right, left, left + 1) )
        ans += solve(left + 2, right);

    if( is_valid(left, right, right - 1, right) )
        ans += solve(left, right - 2);

    if( is_valid(left, right, left, right) )
        ans += solve(left + 1, right - 1);

    return dp[left][right] = ans;

}
int main()
{
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        cin >> reqs[i].l >> reqs[i].sign >> reqs[i].r;
    }

    memset(dp, -1, sizeof dp);

    cout << solve(1, 2*n) << endl;

    return 0;
}