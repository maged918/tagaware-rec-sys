//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define MAX 400005
#define ll long long

int tree[MAX], n;
int a[MAX], b[MAX];
ll l[MAX], r[MAX];

set<ll> s;

void update(int idx, int val){
    while(idx<=n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx){
    int sum = 0;
    while(idx>0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main(){
    int h, q;
    scanf("%d %d", &h, &q);

    ll left, right;
    left = pow(2ll, h-1);
    right = pow(2ll, h) - 1;

    s.insert(left);
    s.insert(right);

    vector<ll> vec;
    ll x, y;
    for(int i=0 ; i<q ; i++){
        scanf("%d %I64d %I64d %d", &a[i], &l[i], &r[i], &b[i]);
        x = l[i] * pow(2ll, (h - a[i]));
        y = r[i] * pow(2ll, (h - a[i])) + pow(2ll, (h - a[i])) - 1;
        s.insert(x);
        s.insert(y);
        if(x>left)
            s.insert(x-1);
        if(y<right)
            s.insert(y+1);
    }

    for(set<ll>::iterator i = s.begin() ; i != s.end() ; i++)
        vec.push_back(*i);

    n = vec.size();

    for(int i=0 ; i<q ; i++){
        x = l[i] * pow(2ll, (h - a[i]));
        y = r[i] * pow(2ll, (h - a[i])) + pow(2ll, (h - a[i])) - 1;

        int c, d;
        c = (int)(lower_bound(vec.begin(), vec.end(), x) - vec.begin()) + 1;
        d = (int)(lower_bound(vec.begin(), vec.end(), y) - vec.begin()) + 1;

        if(b[i] == 1){
            update(1, -1);
            update(c, +1);
            update(d+1, -1);
        } else {
            update(c, -1);
            update(d+1, +1);
        }
    }

    int count = 0, ans = -1;
    for(int i=1 ; i<=n ; i++){
        int temp = query(i);
        if(temp == 0){
            count++;
            ans = i-1;
        }
    }

    if(count == 0){
        printf("Game cheated!\n");
    } else if(count == 1){
        ll answer;
        answer = vec[ans];
        printf("%I64d\n", answer);
    } else {
        printf("Data not sufficient!\n");
    }

    return 0;
}