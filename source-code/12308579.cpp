//Language: GNU C++11


#include<bits/stdc++.h>

using namespace std;
char a[200005],b[200005];

void proc(char* a,int from, int to){
    if((from-to)&1) return;
    int n = to - from;
    proc(a,from,from+n/2);
    proc(a,to-n/2,to);
    if(strncmp(a+from,a+from+n/2,n/2)>0) for(int i = from; i < from + n / 2; i++) swap(a[i],a[i+n/2]);
}

int main(){
    cin>>a>>b;
    int n = strlen(a);
    proc(a,0,n);
    proc(b,0,n);
    //cout<<a<<" "<<b<<endl;
    if(strcmp(a,b)){
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
    }
    return 0;

}
