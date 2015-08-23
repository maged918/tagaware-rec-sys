//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
 
int main() {
        int n, r, ans = 0, pos = 0;
        char op;
 
        scanf("%d", &n);
        bool roger[1000005] = {false};
        for (int i = 0; i < n; ++i)
        {
                scanf(" %c %d", &op, &r);
                if(op == '+'){
                        pos++;
                        roger[r] = true;
                        ans = max(ans, pos);
                }
                else{
                        if(roger[r]){
                                pos--;
                                roger[r] = false;
                        }
                        else ans++;
                }
 
        }
        printf("%d\n", ans > pos ? ans : pos);
    return 0;
}