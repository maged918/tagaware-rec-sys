//Language: GNU C++


#include <iostream>
#include <vector>

using namespace std;

struct Number
{
    int occurances, first_index, last_index;
    Number()
    {
        occurances = 0;
        first_index = 0;
        last_index = 0;
    }
};

int arr[100000];
Number arr2[1000001];

int main()
{
    int max_ = 0, n;
    vector<Number> maxes;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr2[arr[i]].occurances == 0)
            arr2[arr[i]].first_index = i;
        arr2[arr[i]].occurances++;
        arr2[arr[i]].last_index = i;

        if (arr2[arr[i]].occurances > max_)
        {
            maxes.clear();
            maxes.push_back(arr2[arr[i]]);
            max_ = arr2[arr[i]].occurances;
        } else if (arr2[arr[i]].occurances == max_)
            maxes.push_back(arr2[arr[i]]);
    }

    int min_ = 100000;
    Number* for_print = NULL;
    for (int i = 0; i < maxes.size(); i++)
    {
        if (maxes[i].last_index - maxes[i].first_index < min_)
        {
            for_print = &maxes[i];
            min_ = maxes[i].last_index - maxes[i].first_index;
        }
    }

    cout << endl << for_print -> first_index + 1 << " " << for_print -> last_index + 1 << endl;

    return 0;
}
