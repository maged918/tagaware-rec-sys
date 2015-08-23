//Language: GNU C++11


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
int num[6];
bool allsame()
{
    int temp;
    temp = num[1];
    for (int i = 1; i < 6; i++)
    {
        if (temp != num[i]) return false;
    }
    return true;
}
int main()
{
    int sum = 0;
    int hi = 0;
    int now = 0;
    int flag = 0; //0 이면 다함께 증가 1이면 왼쪽 증가 2면 오른쪽 증가 3이면 다 감소
    for (int i = 0; i < 6; i++)
    {
        cin >> num[i];
        
    }
    hi = num[1] + num[2];
    now = num[0] *2 +1;
    sum += now;
    if (num[1] == num[5])
    {
        for (int i = 1; i < num[1]; i++)
        {
            now += 2 ;
            sum += now  ;
        }
        for (int i = num[1]; i <hi; i++)
        {
            sum += now - 2 * (i - num[1]);
        }
    }
    if (num[1] > num[5])
    {
        for (int i = 1; i < num[5]; i++)
        {
            now += 2;
            sum += now;
        }
        now += 1;
        sum += now;
        for (int i = num[5] + 1; i <num[1]; i++)
        {

            sum += now;
        }
        now -= 1;
        sum += now;
        for (int i = num[1] + 1; i <hi; i++)
        {
            sum += now - 2 * (i - num[1]);
        }
    }
    if (num[1] < num[5])
    {
        for (int i = 1; i < num[1]; i++)
        {
            now += 2 ;
            sum += now;
        }
        now += 1;
        sum += now;
        for (int i = num[1] + 1; i <num[5]; i++)
        {   
            
            sum += now;
        }
        now -= 1;
        sum += now;
        for (int i = num[5] + 1; i <hi; i++)
        {
            sum += now - 2 * (i - num[5] );
        }
    }
    cout << sum << endl;
    return 0;
}