//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
char in[300010];
int main(void)
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        memset(in, 0, sizeof(in));
        scanf("%s", in);
        int len=strlen(in), ori=0;
        bool tt=false;
        for(int i=0; i<len; i++){
            if(!tt&in[i]=='.') tt=true;
            else if(in[i]=='.') ori++;
            else tt=false;
        }
        for(int i=0; i<m; i++){
            char tmp;
            int tp;
            int ans=ori;
            scanf("%d", &tp);
            tp--;
            getchar();
            scanf("%c", &tmp);
            if(tmp=='.'){
                if(in[tp]!='.'){
                    if(tp>0&&in[tp-1]=='.') ans++;
                    if(tp<len-1&&in[tp+1]=='.') ans++;
                }
            }else{
                if(in[tp]=='.'){
                    if(tp>0&&in[tp-1]=='.') ans--;
                    if(tp<len-1&&in[tp+1]=='.') ans--;
                }
            }
            ori=ans;
            in[tp]=tmp;
            printf("%d\n", ans);
        }
    }
}
