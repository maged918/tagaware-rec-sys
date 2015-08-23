//Language: GNU C++


#include <cstring>
#include <iostream>

#define MAXN 1000010
using namespace std;

bool isIn[MAXN];

int main()
{
    memset(isIn, false, sizeof(isIn));

    int n;  cin >> n;

    char key;
    int ID;
    int now=0, Max=0;
    for(int i=0;i<n;i++){
        cin >> key >> ID;
        if(key=='+'){
            isIn[ID]=true;
            now++;
            if(now>Max) Max=now;
        }
        else{
            if(isIn[ID]){
                now--;
                isIn[ID]=false;
            }
            else{
                Max++;
            }
        }
    }

    cout << Max << endl;
    return 0;
}
