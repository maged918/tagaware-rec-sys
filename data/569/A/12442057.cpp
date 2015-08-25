//Language: GNU C++


#include <cstdio>
using namespace std;
int main()
{
    int i, j, k, n, m, t, p, q;

    while(scanf("%d %d %d", &t, &j, &q)==3)
    {
        q=q-1;p=j;m=0;
        while(j<t)
        {
            for( i=1; i<=j; i++)
            {
                p+=q;
            }
            j=p;m++;
        }
        printf("%d\n", m);
    }
    return 0;
}
