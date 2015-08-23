//Language: GNU C++


#include <iostream>
using namespace std;
#include <algorithm>
#include <utility>
bool a[1000001];
pair <char, int> q[110];
int main(){
    int n, id, i, num = 0,m=-1;
    char c;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> q[i].first >> q[i].second;
        if (q[i].first == '+'){
            a[q[i].second] = 1;
        }
        if (q[i].first == '-'){
            if (a[q[i].second] == 0){
                num++;
            }
            else{
                a[q[i].second] = 0;
            }
        }
    }
    int num1 = 0;
    for (i = 0; i < 1000001; i++)
        a[i] = 0;

    for (i = 0; i < n; i++){
        if (q[i].first == '+'){
            a[q[i].second] = 1;
            num1++;
            m = max(m, num + num1);
        }
        if (q[i].first == '-'){
            m = max(m, num + num1);
            if (a[q[i].second] == 0){
                num--;
            }
            else{
                a[q[i].second] = 0;
                num1--;
            }
        }
    }
    cout << m;
}