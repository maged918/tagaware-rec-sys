//Language: GNU C++11


#include <iostream>
#include <cstring>

using namespace std;

string s1, s2;

bool equal(int start1, int start2, int length) {
    
    bool suc = true;
    for (int i = 0; i < length && suc; ++i)
        suc &= s1[start1 + i] == s2[start2 + i];
    
    return suc;
    
}

bool equiv(int start1, int start2, int length) {
    
    if (length == 1)
        return s1[start1] == s2[start2];
    
    return equal(start1, start2, length) || (
                (length % 2 == 0) && (
                        (equiv(start1, start2, length/2) && equiv(start1 + length/2, start2 + length/2, length/2)) ||
                        (equiv(start1, start2 + length/2, length/2) && equiv(start1 + length/2, start2, length/2))
                )
            );
    
}

int main() {
    
    cin >> s1 >> s2;
    if (equiv(0, 0, s1.size()))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return  0;
    
}