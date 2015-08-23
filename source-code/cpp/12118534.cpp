//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

int main() {

    long int n, x, a, apples;

    map<long int, long int> negativos;
    map<long int, long int> positivos;

    while (scanf("%d", &n) == 1) {

        apples = 0l;

        while (n--) {

           scanf("%d %d", &x, &a);

           if (x < 0) {

                negativos.insert(pair<long int,long int>(abs(x), a));

           } else {

                positivos.insert(pair<long int,long int>(x, a));
           }
        }

        map<long int, long int>::iterator itp;
        map<long int, long int>::iterator itn;
        itn = negativos.begin();
        itp = positivos.begin();

        if (negativos.size() == positivos.size()) {

            while (itp != positivos.end()) {

                apples += (*itp).second;
                apples += (*itn).second;
                itn++;
                itp++;
            }

        } else if (negativos.size() > positivos.size()) {

            while (itp != positivos.end()) {

                apples += (*itp).second;
                apples += (*itn).second;
                itn++;
                itp++;
            }

            apples += (*itn).second;

        } else {

            while (itn != negativos.end()) {

                apples += (*itp).second;
                apples += (*itn).second;
                itn++;
                itp++;
            }

            apples += (*itp).second;
        }

        printf("%d\n", apples);

        negativos.clear();
        positivos.clear();

    }

    return 0;
}