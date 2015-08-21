//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
    int n, m, candWin[105]={0}, winner, maxV, vote;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; ++i){
        maxV=-55555;
        for(int j=1; j<=n; ++j){
            scanf("%d", &vote);
            if(vote > maxV){
                maxV = vote; winner = j;
            }
        }
        ++candWin[winner];
    }
    vote = -5555;
    for(int i=1; i<=n; ++i){
        if(candWin[i] > vote){
            vote = candWin[i]; winner = i;
        }
    }
    printf("%d\n", winner);
    return 0;
}
