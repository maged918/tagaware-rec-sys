//Language: GNU C++11


#include <iostream>
#include <iomanip>
#include <math.h> 
#include<vector>
#include <algorithm>  
#include <functional> 
using namespace std;
bool isContain(int* number_list,int num)
{
    if(number_list[num-1]==-1)
    {
        return true;
    }
    else
    {
        number_list[num-1]=-1;
        return false;
    }
}
int main()
{
    int toFillIndexArray[100000]={};
    int fillIndex=0;
    
    int n,temp;
    cin>>n;
    if(n==1)
        cout<<n;
    else
    {
        int *number_list = new int[n];
        int standard[100000]={};

        for(int i=0;i<n;i++)
        {
            standard[i]=i+1;
        }
        for(int i=0;i<n;i++)
        {

            cin>>temp;

            if(temp>n||isContain(standard,temp))
                toFillIndexArray[fillIndex++]=i;
            number_list[i]=temp;
            standard[temp-1]=-1;

        }
        int toFillIndex=0;
        for(int i=0;i<n;i++)
        {
            if(standard[i]!=-1)
            {
                number_list[toFillIndexArray[toFillIndex++]]=standard[i];
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<number_list[i]<<" ";
        }


    }
    //system("pause");
    return 0;

}

