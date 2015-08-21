//Language: MS C++


#include <iostream>
#include <algorithm> 

using namespace std;


int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < n - 1; i++)
    for (int j = i+1; j < n; j++)
    {
        if (a[i]>a[j])
        {int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        temp = b[i];
        b[i] = b[j];
        b[j] = temp;
        }
    }
    int k = 0;
    int m = 0;
    while (a[k] <= 0)
    {
        m++;
        k++;
    }
    int sum = 0;
    for (int i = 0; i < min(m, n - m); i++)
        sum = sum + b[m - 1 - i] + b[m + i];
    if (n - m>m)
        sum += b[2 * m];
    else
    if (n - m < m)
        sum += b[2 * m - n - 1];
    //for (int i = 0; i < n; i++)
        cout << sum;

    return 0;
}