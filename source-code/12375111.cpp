//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define MAX 200005

set<int> one, two;
bool visited[MAX];

int main(){
    int n, k, a, x, c, d, num1, num2, temp, number;
    scanf("%d %d %d", &n, &k, &a);  

    int m;
    scanf("%d", &m);

    one.insert(0);
    one.insert(n+1);

    two.insert(0);
    two.insert(-(n+1));

    int total = (n+1) / (a+1);

    for(int i=0 ; i<m ; i++){
        scanf("%d", &x);
        if(visited[x]){
            continue;
        }

        c = *one.upper_bound(x);
        d = -(*two.upper_bound(-x));

        temp = (c - d) / (a+1);
        num1 = (c - x) / (a+1);
        num2 = (x - d) / (a+1);
        int change = temp - (num1 + num2);
        total -= max(0, change);    
        if(total<k){
            cout<<i+1<<endl;
            return 0;
        }

        one.insert(x);
        two.insert(-x);
        visited[x] = true;
    }

    cout<<-1<<endl;

    return 0;
}