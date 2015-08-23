//Language: GNU C++


#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> timeline(n+1, 0);
    int inside[1000010];
    for (int i = 0; i < 1000010; ++i) inside[i] = 0;
    for (int i = 1; i < n+1; ++i) {
        char t;
        int num;
        scanf("\n%c %d", &t, &num);
        if ((inside[num] == 0) && (t == '-')) {
            for (int j = 0; j < i; ++j) {
                   timeline[j]++;
               }
            timeline[i] = timeline[i-1]-1;
            inside[num] = 1;
        } else if (t == '+') {
            timeline[i] = timeline[i-1]+1;
            inside[num] = 2;
        } else if (t == '-') {
            inside[num] = 1;
            timeline[i] = timeline[i-1]-1;
        } else {
            cout << "Something wrong!";
        }
    }
    int m = 0;
    for (int i = 0; i < n+1; ++i) 
        if (m < timeline[i]) m = timeline[i];
    
    cout << m << endl;
    return 0;
}