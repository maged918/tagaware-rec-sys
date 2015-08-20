//Language: GNU C++


    // nhatnguyendrgs (c) 2015
     
    #include "iostream"
    #include "stdio.h"
    #include "stdlib.h"
    #include "string"
    #include "string.h"
    #include "algorithm"
    #include "math.h"
    #include "vector"
    #include "map"
    #include "queue"
    #include "stack"
    #include "deque"
    #include "set"
    #define read freopen("C:\\Users\\Windows\\Documents\\Code\\sample.inp","r",stdin)
    #define write freopen("C:\\Users\\Windows\\Documents\\Code\\sample.out","w",stdout)
    using namespace std;
     
    typedef long long int_64;
    typedef pair<int, int> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    const int_64 MaxN = 1e6 + 4;
    const int_64 inf = 1e9;
    const int_64 base = 1e9 + 7;
     
    int n,r;
    char sign;
    int a[MaxN], person,result;
     
    int main(){
        cin>>n;
        for (int i = 0; i < n; i++){
            cin>>sign>>r;
            if (sign == '+'&&a[r]==0){
                    person++;
                    a[r] = 1;
            }
            else{
                if (a[r]==0){
                    result++;
                }
                else{
                    person--;
                    a[r] = 0;
                }
            }
            result = max(result, person);
        }
        cout<<result<<endl;
        return 0;
    }