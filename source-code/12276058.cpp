//Language: GNU C++


#include <iostream>
using namespace std;

bool board[1002][1002];

int w,h;

bool clear() {
    for (int i=0;i<1002;++i)
        for (int j=0;j<1002;++j)
            board[i][j]=false;
        
    return true;
}

void fill1(int startY, int startX, int height, int width) {
    for (int i=startY,c=0; c<height; ++c,++i) {
        for (int j=startX,d=0; d<width; ++d,++j) {
            board[i][j] = true;
        }
    }
}

bool can(int s, int n) {
    for (int i=0;i<h;++i) {
        for (int j=0;j<w;++j) {
            if (board[i][j] == false) {
                int k=j;
                for (;k<w&&!board[i][k];++k);
                    
                //cout << j << " --> " << k << " < " << n << endl;
                    
                if ((k-j)<n)
                    continue;
                    
                for(k=i;k<h&&!board[k][j];++k);
                
                if ((k-i)<s)
                    continue;
                
                //cout << "-- fill " << i << " " << j << " " << s << " " << n << endl;
                fill1(i,j,s,n);
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    cin >> w >> h;
    
    int a[4];
    for (int i=0;i<4;++i)
        cin >> a[i];
    
    if (clear()&&can(a[0],a[1])&&can(a[2],a[3]))
        cout << "YES";
    else if (clear()&&can(a[0],a[1])&&can(a[3],a[2]))
        cout << "YES";
    else if (clear()&&can(a[1],a[0])&&can(a[2],a[3]))
        cout << "YES";
    else if (clear()&&can(a[1],a[0])&&can(a[3],a[2]))
        cout << "YES";
    else if (clear()&&can(a[2],a[3])&&can(a[0],a[1]))
        cout << "YES";
    else if (clear()&&can(a[3],a[2])&&can(a[0],a[1]))
        cout << "YES";
    else if (clear()&&can(a[2],a[3])&&can(a[1],a[0]))
        cout << "YES";
    else if (clear()&&can(a[3],a[2])&&can(a[1],a[0]))
        cout << "YES";
    else
        cout << "NO";
}