//Language: GNU C++11


#include<iostream>

using namespace std;

int a[1000005][3];

int main(){
	ios_base::sync_with_stdio(false);

    int n, x, y, l;

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;

        a[x][2]++;
        if(a[x][0] == 0){
            a[x][0] = i + 1;
            a[x][1] = i + 1;
            continue;
        }

        a[x][1] = i + 1;

    }

    x = 0; y = 1000005; l = 0;
    for(int i = 1; i < 1000001; ++i){
        if(a[i][2] >= l && a[i][2] > 0){
            if(a[i][2] == l)
                 if((a[i][1] - a[i][0]) > (y - x))
                    continue;

            y = a[i][1];
            x = a[i][0];
            l = a[i][2];

        }
    }


    cout << x << ' ' << y;

return 0;
}
