//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int a1, b1;
    int a2, b2;
    int a3, b3;
    long s1, s2, s3;

    std::cin >> a1 >> b1;
    if (a1 > b1) {
        std::swap(a1, b1);
    }

    s2 = a2 * b2;
    std::cin >> a2 >> b2;
    if (a2 > b2) {
        std::swap(a2, b2);
    }

    s2 = a2 * b2;
    std::cin >> a3 >> b3;
    if (a3 > b3) {
        std::swap(a3, b3);
    }
    s3 = a3 * b3;
/*    
    std::cout << a1 << " " << b1 << " " << s1 << std::endl;
    std::cout << a2 << " " << b2 << " " << s2 << std::endl;
    std::cout << a3 << " " << b3 << " " << s3 << std::endl;
*/

/*
    if (s1 < s2 + s3) {
        std::cout << "NON" << std::endl;
        return 0;
    }
*/

    bool one_fit = false;
    for (int index = 0; index < 2; ++index) {
        if ((b2 <= b1) && (a2 <= a1)) {
            int a4, b4;
            int a5, b5;
            int a6, b6;
            int a7, b7;
            int a8, b8;

            a4 = a2;
            b4 = b1 - b2;

            a5 = a1 - a2;
            b5 = b2;

            a6 = a1 - a2;
            b6 = b1 - b2;

            a7 = a1 - a2;
            b7 = b1;

            a8 = a1;
            b8 = b1 - b2;

/*
            std::cout << a4 << " " << b4 << std::endl;
            std::cout << a5 << " " << b5 << std::endl;
            std::cout << a6 << " " << b6 << std::endl;
            std::cout << a7 << " " << b7 << std::endl;
            std::cout << a8 << " " << b8 << std::endl;
*/            

            one_fit = false;

            if (((a3 <= a4) && (b3 <= b4)) || ((b3 <= a4) && (a3 <= b4))) {
                if ((a4 == 0) || (b4 == 0)) {
                    break;
                }
                one_fit = true;
            }
            if (((a3 <= a5) && (b3 <= b5)) || ((b3 <= a5) && (a3 <= b5))) {
                if ((a5 == 0) || (b5 == 0)) {
                    break;
                }
                one_fit = true;
            }
            if (((a3 <= a6) && (b3 <= b6)) || ((b3 <= a6) && (a3 <= b6))) {
                if ((a6 == 0) || (b6 == 0)) {
                    break;
                }
                one_fit = true;
            }
            if (((a3 <= a7) && (b3 <= b7)) || ((b3 <= a7) && (a3 <= b7))) {
                if ((a7 == 0) || (b7 == 0)) {
                    break;
                }
                one_fit = true;
            }
            if (((a3 <= a8) && (b3 <= b8)) || ((b3 <= a8) && (a3 <= b8))) {
                if ((a8 == 0) || (b8 == 0)) {
                    break;
                }
                one_fit = true;
            }
            
            if (one_fit) {
                std::cout << "YES" << std::endl;
                return 0;
            }
        }

        std::swap(a2, b2);
    }

    if (one_fit) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    // std::cout << calculateShift(sequence) << std::endl;
    return 0;
}

