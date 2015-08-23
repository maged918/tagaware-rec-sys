//Language: GNU C++11


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int numCities;
    cin >> numCities;
    //cout << numCities;

    int* coords = new int[numCities];
    for (int i = 0; i < numCities; i++) {
        cin >> coords[i];
        //cout << coords[i];
    }

    const int first = coords[0];
    const int last = coords[numCities-1];

    cout << (coords[1] - first) << ' ' << last - first << endl;
    for (int i = 1; i < numCities-1; i++) {
        int min = std::min(coords[i] - coords[i-1], coords[i+1] - coords[i]);
        int max = std::max(last - coords[i], coords[i] - first);
        cout << min << ' ' << max << endl;
    }
    cout << (coords[numCities-1] - coords[numCities-2]) << ' ' << last - first << endl;
}
