//Language: GNU C++


#include <iostream>

using namespace std;

int main()
{
    int a1, a2, a3, b1, b2, b3;

    int temp1, temp2;
    cin>>temp1>>temp2;

    a1 = min(temp1, temp2);
    b1 = max(temp1, temp2);

    cin>>temp1>>temp2;

    a2 = min(temp1, temp2);
    b2 = max(temp1, temp2);

    cin>>temp1>>temp2;

    a3 = min(temp1, temp2);
    b3 = max(temp1, temp2);

    if(b3 > b1 || b2 > b1)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    if(a3 > a1 || a2 > a1)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    if((a1*b1) < (a2*b2 + a3*b3))
    {
        cout<<"NO"<<endl;
        return 0;
    }

    if((b2 + b3 <= b1) || (a2 + a3 <= a1))
    {
        cout<<"YES"<<endl;
        return 0;
    }
    
    if((b2 + a3 <= b1) && (max(a2, b3) <= a1))
    {
        cout<<"YES"<<endl;
        return 0;
    }

    if((b3 + a2) <= b1 && (max(b2, a3) <= a1))
    {
        cout<<"YES"<<endl;
        return 0;
    }

    if((a2 + a3) <= b1 && max(b2, b3) <= a1)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;
    return 0;
    

}
