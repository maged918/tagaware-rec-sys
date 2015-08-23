//Language: GNU C++


#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int N = 1<<17;

struct node{
    int sum, col;
    bool pp;
};

struct STree{
    node t[N+N];

    void push(int v, int tl, int tr){
        if (!t[v].pp) return;
        t[v].sum = (tr-tl+1) * t[v].col;
        if (v < N){
            t[v+v].col = t[v].col; t[v+v].pp = 1;
            t[v+v+1].col = t[v].col; t[v+v+1].pp = 1;
        }
        t[v].pp = 0;
    }

    void color(int l, int r, int x, int v = 1, int tl = 0, int tr = N-1){
        push(v,tl,tr);
        if (tl > r || l > tr) return;
        if (tl >= l && tr <= r){
            t[v].col = x;
            t[v].pp = 1;
            push(v,tl,tr);
            return;
        }
        int tm = (tl+tr) >> 1;
        color (l,r,x,v+v,tl,tm);
        color (l,r,x,v+v+1,tm+1,tr);
        t[v].sum = t[v+v].sum + t[v+v+1].sum;
    }
    int getSum(int l, int r, int v = 1, int tl = 0, int tr = N-1){
        push(v,tl,tr);
        if (tl > r || l > tr) return 0;
        if (tl >= l && tr <= r) return t[v].sum;
        int tm = (tl+tr) >> 1;
        return getSum(l,r,v+v,tl,tm) + getSum(l,r,v+v+1,tm+1,tr);
    }
    int get(int x){
        x += N;
        int res = t[x].sum;
        while (x){
            if (t[x].pp) res = t[x].col;
            x >>= 1;
        }
        return res;
    }

}T[27];

string s;

void debug(int k){
    for (int i = 0; i < k; i++){
        cout << char(i+'a') << ": ";
        for (int j = 0; j < s.length(); j++)
            cout << T[i].get(j);
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int n, q;
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        T[s[i]-'a'].t[i+N].sum = 1;
    }
    for (int i = 0; i < 26; i++){
        for (int j = N-1; j > 0; j--)
            T[i].t[j].sum = T[i].t[j+j].sum + T[i].t[j+j+1].sum;
    }
   // debug(4);
    int l, r, k;
    for (int i = 0; i < q; i++){
        cin >> l >> r >> k;
        l--, r--;
        if (k == 0){
     //       cout << l << " " << r << endl;
            int x = l, cnt;
            for (int j = 25; j >= 0; j--){
                cnt = T[j].getSum(l,r);
       //         if (cnt) cout << char(j+'a') << " " << cnt << " " << x << endl;
                T[j].color(l,r,0);
                T[j].color(x,x+cnt-1,1);
                x += cnt;
            }
        }else{
            int x = l, cnt;
            for (int j = 0; j < 26; j++){
                cnt = T[j].getSum(l,r);
                T[j].color(l,r,0);
                T[j].color(x,x+cnt-1,1);
                x += cnt;
            }
        }
  //      debug(4);
    }
  //  debug(4);
    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < 26; j++)
            if (T[j].get(i) == 1){
                cout << char(j+'a');
                break;
            }
    }

    return 0;
}
