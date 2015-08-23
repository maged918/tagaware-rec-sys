//Language: MS C++


#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    if(a2 + a3 <= a1 && max(b2,b3) <= b1) cout << "YES";
    else if(a2 + a3 <= b1 && max(b2,b3) <= a1) cout << "YES";
    else if(a2 + b3 <= b1 && max(a3,b2) <= a1) cout << "YES";
    else if(a2 + b3 <= a1 && max(a3,b2) <= b1) cout << "YES";
    else if(a3 + b2 <= b1 && max(a2,b3) <= a1) cout << "YES";
    else if(a3 + b2 <= a1 && max(a2,b3) <= b1) cout << "YES";
    else if(b3 + b2 <= b1 && max(a2,a3) <= a1) cout << "YES";
    else if(b3 + b2 <= a1 && max(a2,a3) <= b1) cout << "YES";
    else cout << "NO";
    return 0;
}