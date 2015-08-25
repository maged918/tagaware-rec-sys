//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#define INF 1000000002
int scan()
{ int noRead=0;
    char p= getchar();
    for(;p<33;)
    { p=getchar(); }
    while(p>32)
        {
            noRead = (noRead << 3) + (noRead << 1) + (p - '0');
            p=getchar();
        }
    return noRead;
}

using namespace std;
int a[100002];
int has[100002];
vector<int> vec;
int main(void){
    for(int i = 0; i < 100002; ++i)
        has[i] = 0;
    int n = scan();

    for(int i = 0; i < n; ++i) {
        a[i] = scan();
        if(a[i] > n) {
            vec.push_back(i);
            continue;
        }
        if(has[a[i]] == 0 )
            has[a[i]] = a[i];
        else {
            vec.push_back(i);
        }
    }
        if ( n == 1) {
        printf("1");
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        if(has[i] == 0) {
            int nvec = vec.size();
            int index = vec[nvec-1];
            vec.pop_back();
            a[index] = i;
        }
    }
    for(int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        if( i != n-1)
            printf(" ");
    }



    return 0;

}

