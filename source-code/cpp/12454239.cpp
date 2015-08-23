//Language: GNU C++


#include<stdio.h>

class bunsu {
public:
    int u;
    int d;

    bunsu(int u, int d) {
        int g = gcd(u, d);
        this->u = u / g;
        this->d = d / g;
    }
    bool operator<(const bunsu& p)const {
        return u*p.d < p.u*d;
    }
    bool operator>(const bunsu& p)const {
        return u*p.d > p.u*d;
    }
    bunsu operator-(const bunsu& p) {
        return bunsu((u*p.d) - (p.u*d), d*p.d);
    }
    bunsu operator+(const bunsu& p) {
        return bunsu((u*p.d) + (p.u*d), d*p.d);
    }
    bunsu operator*(const bunsu& p) {
        return bunsu(u*p.u, d*p.d);
    }
    bunsu operator/(const bunsu& p) {
        return bunsu(u*p.d, d*p.u);
    }


    void operator-=(const bunsu& p) {
        *this = bunsu((u*p.d) - (p.u*d), d*p.d);
    }
    void operator+=(const bunsu& p) {
        *this = bunsu((u*p.d) + (p.u*d), d*p.d);
    }
    void operator*=(const bunsu& p) {
        *this = bunsu(u*p.u, d*p.d);
    }
    void operator/=(const bunsu& p) {
        *this = bunsu(u*p.d, d*p.u);
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a%b);

    }


};




int main() {
    int T, S, q;
    scanf("%d%d%d", &T, &S, &q);
    int cnt = 0;
    while (T > S) {
        cnt++;
        S *= q;
    }
    printf("%d", cnt);


}