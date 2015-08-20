//Language: GNU C++


#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream f1("input.in");
istream& f= cin;
#define NMAX 200200

char a[NMAX], b[NMAX];

bool egal(int st1, int dr1, int st2)
{
    for (int i= st1, j= st2; i<= dr1; i++, j++)
        if (a[i] != b[j])
            return false;

    return true;
}

bool equivalent(int st1, int dr1, int st2, int dr2)
{
    if ( egal(st1, dr1, st2) )
        return true;

    if ( (dr1 - st1 + 1) % 2 == 0 )
    {
        int m1= (st1+dr1+1)/2;
        int m2= (st2+dr2+1)/2;

        if ( equivalent(st1, m1-1, st2, m2-1) && equivalent(m1, dr1, m2, dr2) )
            return true;
        else
            if (equivalent(st1,m1-1 , m2, dr2) && equivalent(m1, dr1, st2, m2-1))
                return true;

    }

    return false;
}

int main()
{
    f>>a;
    f>>b;

    if (equivalent(0, strlen(a)-1, 0, strlen(b)-1 ) )
        cout<<"YES";
    else
        cout<<"NO";


    return 0;
}
