//Language: GNU C++


#include<iostream>
#include<algorithm>

using namespace std;



int main()
{
    int n, l[100000], min=0, max=0;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for (size_t i = 0; i < n; i++)
    {
    
            min=0;
            max=0;
            if (i==0)
            {
                min = abs(l[i + 1] - l[i]);
                max = abs(l[n-1] - l[i]);
            }
            else if(i==n-1)
            {
                max=abs(l[n-1]-l[0]);
                min=abs(l[n-1]-l[n-2]);
            }
            else
            {
                if (abs(l[i]-l[i-1])<abs(l[i+1]-l[i]))
                {
                    min = abs(l[i] - l[i - 1]);
                }
                else
                {
                    min = abs(l[i + 1] - l[i]);
                }
                if (abs(l[n-1]-l[i])>abs(l[i]-l[0]))
                {
                    max = abs(l[n-1] - l[i]);
                }
                else
                {
                    max = abs(l[i] - l[0]);
                }
            }
        
    
        
        cout << min << " " << max << endl;
    }
    
}