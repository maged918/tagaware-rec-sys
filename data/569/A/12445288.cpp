//Language: GNU C++11


#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <queue>
//#include <cstdlib>

using namespace std;

#define max_num 100005

int main(void){
	long int T, S, q, num = 1;
	cin >> T >> S >> q;
	register int i, j, temp = S;
	while(temp*q < T){
        temp = temp*q;
        num++;
    }
    cout << num << endl;
}
