//Language: GNU C++11


#include<bits/stdc++.h>

using namespace std;

int main()
{

    int i,j,k,l,m,n,mcnt,sub,rd,koto,q;

    cin>>koto>>rd>>q;

    int len=rd;

    int inc=q-1;

    for(i=1;;i++)
    {
        len+=(len*inc);

        if(len>=koto)
        {
            break;
        }
    }

    printf("%d\n",i);

    return 0;
}
