//Language: GNU C++


#include <iostream>
using namespace std;

int main() {
int T,S,q;
cin>>T;
cin>>S;
cin>>q;
int i = 0;

    
while(S<T){
    S= S*q;
    i++;
    
 
}
cout<<i;

    return 0;
}
