//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() 
{
    int T, S, Q;
    cin >> T >> S >> Q;

    double ratio = (double)(Q - 1) / Q , downloaded = S;

    int c = 1;
    for (int i = 1; i <= T; i++)
    {
        downloaded = S + ratio * i;
        
        if (downloaded >= T)
        {
            break;
        }


        if (downloaded <= i)
        {
            S = downloaded;
            c++;
            i = 0;
        }

    }

    cout << c;

}
