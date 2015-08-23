//Language: GNU C++


#include <iostream>
using namespace std;
int m[1000000], f[1000000];
int main()
{
    int n, x, imax = 0, imin =0x7fffffff , c = -1;
	cin >> n;
    for(int i = 0; i < n; ++i)
    {
		cin >> x;
        if(!m[x]) f[x] = i;
        if(++m[x] > imax)
        {
            imax = m[x];
            imin = i - f[x] + 1;
            c = f[x] + 1;
        } else if(m[x] == imax && i - f[x] + 1 < imin) {
            imin = i - f[x] + 1;
            c = f[x] + 1;
        }
    }
    cout << c << " " << c + imin - 1;
    return 0;
}

     	  		  	   	 	 	  	 			 	