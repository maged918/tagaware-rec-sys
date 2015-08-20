//Language: GNU C++


#include<iostream>
using namespace std;

int check_possible(int X,int Y,int x1,int y1,int x2,int y2)
{
    int a=x1+x2;
    int b=y1+y2;
    int c=x1+y2;
    int d=x2+y1;

    //return ((a<=X && b<=Y)||(c<=X && d<=Y)||(d<=X && c<=Y)||(b<=X && a<=Y));
    return (((x1+x2<=X && max(y1,y2)<=Y)||((y1+y2)<=X && max(x1,x2)<=Y)||(x1+y2<=X && max(x2,y1)<=Y)||(y1+x2<=X && max(x1,y2)<=Y))
       ||
       ((x1+x2<=Y && max(y1,y2)<=X)||((y1+y2)<=Y && max(x1,x2)<=X)||(x1+y2<=Y && max(x2,y1)<=X)||(y1+x2<=Y && max(x1,y2)<=X)));
}

int main()
{
    int X,Y,x1,y1,x2,y2;
    cin>>X>>Y>>x1>>y1>>x2>>y2;
    if(check_possible(X,Y,x1,y1,x2,y2))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
