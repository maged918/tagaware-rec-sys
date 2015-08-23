//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int n;
map<int,bool> In;
int main(){
    scanf("%d",&n);
    int  ans = 0 , cnt = 0;
    for(int i=0;i<n;i++){
        getchar();
        char c;int x;
        scanf("%c %d",&c,&x);
        if(c=='+'){
            In[x] = true;
            cnt++;
            ans = max(ans,cnt);
        }else{
            if(!In[x]){
                ans++;
            }else{
                if(cnt)
                    cnt--;
                In[x] = false;
                //ans = max(ans,cnt1+cnt2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
