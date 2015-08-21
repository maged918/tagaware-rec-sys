//Language: GNU C++11


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct e
{
    int num , beg , en;
    e()
    {
        num = 0;
        beg = en = -1;
    }
    bool operator < (const e &a)const
    {
        return num < a.num;
    }
}a[1123456];
int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int p;
        cin >> p;
        if(a[p].beg == -1)
        {
            a[p].num++;
            a[p].beg = i;
        }
        else
        {
            a[p].en =i;
            a[p].num++;
        }
    }
    //sort(a , a + n);
    int change = a[0].num;
    for(int i = 0 ; i < 1123056;i++)
    {
        if(a[i].num > change) change = a[i].num;
    }
    if(change == 1)
    {
        cout << "1 1" <<endl;
        return 0;
    }
    int en = -1;
    int beg = -1;
    int mn = 1000000000;
    for(int i = 1123406 ; i >= 0; i--)
    {
        if(change == a[i].num)
        {
            if((a[i].en - a[i].beg) < mn )
            {
                mn  = a[i].en - a[i].beg;
                en  = a[i].en;
                beg = a[i].beg;
            }
        }
    }
    beg++;en++;
    cout << beg << " " << en << endl;
}




