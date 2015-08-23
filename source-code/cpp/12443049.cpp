//Language: GNU C++


#include <iostream>

using namespace std;



int main()
{
    int n;
    cin >> n;

    bool used[n + 1];
    for(int i = 1; i <= n; i++)
    {
        used[i] = false;
    }

    int numbers[n];
    bool tohandle[n];

    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];

        if(numbers[i] <= n && used[numbers[i]] == false)
        {
            tohandle[i] = false;
            used[numbers[i]] = true;
        }
        else
        {
            tohandle[i] = true;
        }
    }

    int numbertoset = 1;

    for(int i = 0; i < n; i++)
    {
        if(tohandle[i])
        {
            while(used[numbertoset]) numbertoset++;
            numbers[i] = numbertoset;
            used[numbertoset] = true;
        }

        cout << numbers[i] << ' ';
    }

    return 0;
}
