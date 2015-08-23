//Language: GNU C++


#include <iostream>
using namespace std;

#define UI unsigned int

int main(){
    UI i,b,n,m,fmin;
    char s[300002] = {0};
    char l = 0;
    cin >> n >> m >> s;
    for (i=n-1 ; i>0 ; i--){
        l = s[i];
        if (l == '.' && s[i-1] == '.') fmin++;
        s[i+1]=l;
    } s[1] = s[0]; s[0] = 0;
    for (i=0;i<m;i++){
        cin >> b >> l;
        if ((l == '.' && s[b] == '.') || (l != '.' && s[b] != '.') ){
            cout << fmin << "\n" ; s[b] = l ;
            continue;
        }
        n = (s[b+1] == '.') + (s[b-1] == '.');
        if (s[b] == '.'){
            fmin -= n; cout << fmin << "\n" ; s[b] = l ; continue;
        }
        fmin += n; cout << fmin << "\n" ; s[b] = l ;
    }
    return 0;
}