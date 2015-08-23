//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
char str[2][200111];
bool pr=0;
bool scmp(const char *a, const char *b, int n){// <
    for(int i=0; i<n; i++)
        if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}

void sort(char *s, int l, int r){
    if((r-l)%2==1){
        return;
    }
    int m=(l+r)/2;
    sort(s, l, m );
    sort(s, m, r);
    if(scmp(s+l, s+m, (r-l)/2)){
        // XD
    }else{
        for(int i=0; i<(m-l); i++)swap(s[l+i],s[m+i]);
    }
}

void input(){
    scanf("%s%s",str[0],str[1]);
}

void solve(){
    sort(str[0], 0, strlen(str[0]));
    sort(str[1], 0, strlen(str[1]));
    printf("%s\n", strcmp(str[0],str[1])? "NO": "YES");
}

int main(){
    input();
    solve();
}

 	 				 				       					  		 		