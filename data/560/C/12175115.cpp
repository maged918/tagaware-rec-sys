//Language: MS C++


#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;

int main()
{
 //   ifstream cin("input.txt");
   // ofstream cout("output.txt");

    int c1, c2, c3, c4, c5, c6;
    cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

    int tek = c2;
    int answer = 0;

    for (int i = 0; i < min(c1, c3); i++)
    {
        answer += tek + tek + 1;
        tek++;
    }

    if (c1 != c3)
        for (int i = 0; i < abs(c1 - c3); i++)
        {
            answer += tek + tek;
        }

    for (int i = 0; i < min(c4, c6); i++)
    {
        answer += tek + tek - 1;
        tek--;
    }

    cout << answer;
    return 0;
}