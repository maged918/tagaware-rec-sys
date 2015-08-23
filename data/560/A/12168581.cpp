//Language: MS C++


#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
#include<limits.h>

using namespace std;



int main()
{ 
    int n,temp; cin >> n;
    vector<int> in;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;  in.push_back(temp);
    }
    sort(in.begin(), in.end());
    if (in[0] == 1)
        cout << "-1" << endl;
    else
    {
        cout << "1" << endl;
    }
    return 0;
}

