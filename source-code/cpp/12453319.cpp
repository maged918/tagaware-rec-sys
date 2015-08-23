//Language: GNU C++


#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N = 50;
long long A[4010][4010];
#define MOD 1000000007
void init1(){
    A[1][1] = 1;
    A[2][1] = 1;
    A[2][2] = 2;
}
void init2(){
    for(int i = 3; i < 4010; i++){
            for(int j = 1; j < 4010; j++){
                if(j == 1)
                    A[i][j] = A[i-1][i-1];
                else
                    A[i][j] = (A[i][j-1] + A[i-1][j-1])%MOD;
            }
        }
}
int main (){
    init1();
    init2();

             int n;
    scanf("%d",&n);
    cout << A[n+1][n] << endl;
    return 0;
}
