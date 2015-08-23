//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct camp
{
    int a, b;
}point[105];

bool compare (camp x, camp y)
{
    return x.a > y.a;
}

int main ()
{
    int nn, temp1, temp2;
    while (scanf ("%d", &nn)!=EOF)
    {
        int  s=0, cnst1=0, cnst2=0;
        for (int i=0; i<nn; i++)
            scanf ("%d%d", &point[i].a, &point[i].b);
        for (int i=0; i<nn; i++)
        {
            if (point[i].a<0) cnst1++;
            else if (point[i].a>0) cnst2++;
        }
        sort (point, point+nn, compare);

        for (int i=0; i<nn-1; i++)
        {
            if (point[i].a>0 && point[i+1].a<0)
            {
                temp1 = i;
                temp2 = i+1;
                break;
            }
        }

        if (cnst1==cnst2)
        {
            for (int i=0; i<nn; i++)
                s += point[i].b;
        }
        else if (cnst1>cnst2)
        {
            if (cnst2==0) s = point[0].b;
            else
            {
                for (int i=0; i<cnst2+1; i++)
                    s = s + point[temp2++].b;
                for (int i=0; i<cnst2; i++)
                    s = s + point[temp1--].b;
            }
        }
        else if (cnst1<cnst2)
        {
            if (cnst1==0) s = point[cnst2-1].b;
            else
            {
                for (int i=0; i<cnst1; i++)
                    s = s + point[temp2++].b;
                for (int i=0; i<cnst1+1; i++)
                    s = s + point[temp1--].b;
            }
        }
        printf ("%d\n", s);
    }
    return 0;
}

 	   	 	  					  				 		   				