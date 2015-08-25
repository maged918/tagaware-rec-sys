//Language: GNU C++


#include <stdio.h>
#include <iostream>

#define MAX_N 500
#define MAX_M 500
#define MAX_MAP_SIZE MAX_N*MAX_M
#define MODBASE (1000000007)
#define PAIRCNT_SIZE 60*1024*1024
using namespace std;

int n, m, mapSize;
char map[MAX_N+1][MAX_M+2];
//int pairCnt[MAX_MAP_SIZE+1][MAX_MAP_SIZE+1];
int pairCntPos[MAX_N+1][MAX_M+1]; // the first half 
int pairCnt[PAIRCNT_SIZE];  //

int isFirstHalf(int r, int c)
{
    int d1, d2;
    d1 = r-1 + c-1;
    d2 = n-r + m-c;
    if (d1 < d2)
        return 1;
    return 0;
}

void init()
{
    int i;
    for (i=0; i < PAIRCNT_SIZE; i++)
    {
        pairCnt[i] = -1;
    }
    int r, c, lastGSize=0, lastGPos=0;
    
    for (r=1 ; r <= n ; r++)
        for (c=1 ; c <= m ; c++)
        {
            if (!isFirstHalf(r, c))
                continue;
            pairCntPos[r][c]= lastGPos + lastGSize;
      //      cout << "r = " << r << " c = " << c << "pos = " <<  pairCntPos[r][c] << endl;
            lastGPos = pairCntPos[r][c];
            
            if (n>= (r-1+c)) // c = m
            {
                if (m>= (r-1+c))
                    lastGSize = r-1+c;
                else    
                    lastGSize = m;
            }
            else
            {
                lastGSize = n;
            }
        }
}

int insideRect(int r, int c)
{
    if (r>=1 && r <= n && c>=1 && c<= m)
        return 1;
    return 0;
}

int get_pairCnt(int r1, int c1, int r2, int c2)
{
    int pos = pairCntPos[r1][c1];
    int rMin;
    if (n>= (r1-1+c1)) // c = m
    {
        rMin = n-(r1-1+c1)+1;
      
    }
    else
    {
        rMin =1;
    }
//    printf("GET (%d, %d)<->(%d, %d) : %d \n", r1, c1, r2, c2,pairCnt[pos+r2-rMin]);
    return pairCnt[pos+r2-rMin];
}

void set_pairCnt(int r1, int c1, int r2, int c2, int cnt)
{
    int pos = pairCntPos[r1][c1];
    int rMin;
    if (n>= (r1-1+c1)) // c = m
    {
        rMin = n-(r1-1+c1)+1;
      
    }
    else
    {
        rMin =1;
    }
    pairCnt[pos+r2-rMin] = cnt;
//    printf("SET (%d, %d)<->(%d, %d) : %d \n", r1, c1, r2, c2,pairCnt[pos+r2-rMin]);
}

int count(int r1, int c1, int r2, int c2)
{
//    printf("CNT (%d, %d)<->(%d, %d)\n", r1, c1, r2, c2);
    int cnt = 0;
    
    if (!insideRect(r1, c1) || !insideRect(r2, c2))
        return 0;
    
    if ((cnt= get_pairCnt(r1, c1, r2, c2))>=0)
        return cnt;

    if (map[r1][c1] != map[r2][c2])
    {
        set_pairCnt(r1, c1, r2, c2, 0);
        return 0;
    }
    if (r1==1 && c1==1 && r2 == n && c2 == m)
    {
        set_pairCnt(r1, c1, r2, c2, 1);
        return 1;
    }
    cnt = 0;
 //   printf("CNT (%d, %d)<->(%d, %d): cnt %d\n", r1, c1, r2, c2, count(r1-1, c1, r2, c2+1)%MODBASE);
    cnt += (count(r1-1, c1, r2, c2+1) % MODBASE);
 //   printf("CNT (%d, %d)<->(%d, %d): cnt %d\n", r1, c1, r2, c2, cnt);
    cnt %= MODBASE;
//    printf("CNT (%d, %d)<->(%d, %d): cnt %d\n", r1, c1, r2, c2, cnt);
    cnt += (count(r1-1, c1, r2+1, c2) % MODBASE);
    cnt %= MODBASE;
 //   printf("CNT (%d, %d)<->(%d, %d): cnt %d\n", r1, c1, r2, c2, cnt);
    cnt += (count(r1, c1-1, r2, c2+1) % MODBASE);
    cnt %= MODBASE;
//    printf("CNT (%d, %d)<->(%d, %d): cnt %d\n", r1, c1, r2, c2, cnt);
    cnt += (count(r1, c1-1, r2+1, c2) % MODBASE);
    cnt %= MODBASE;
 //   printf("CNT (%d, %d)<->(%d, %d): cnt %d\n", r1, c1, r2, c2, cnt);
    set_pairCnt(r1, c1, r2, c2, cnt);
    return cnt;
}


void find_solution()
{
    int r, c, mi;
    int pCnt = 0;
    int oddPath = 0;
    init();
    
    if ((n+m)%2==0)
    {
        mi = (n+m)/2-1;
        oddPath = 1;
    }
    else
        mi = (n+m)/2;
        
    if (n<=m)    
    {
        r = 1;
        c = mi;
    }
    else
    {
        r = mi-m+1;
        c = m;
    }
   // cout << "r = " << r << " c = " << c << endl;
    for ( ; insideRect(r, c) ; r++, c--)    
    {
        if (oddPath)
        {
            pCnt += count(r, c, r, c+2);
            pCnt %= MODBASE;
            pCnt += count(r, c, r+1, c+1);
            pCnt %= MODBASE;
            pCnt += count(r, c, r+1, c+1);
            pCnt %= MODBASE;
            pCnt += count(r, c, r+2, c);
            pCnt %= MODBASE;
        }
        else
        {
            pCnt += count(r, c, r, c+1);
            pCnt %= MODBASE;
            pCnt += count(r, c, r+1, c);
            pCnt %= MODBASE;
        }
    }
    cout << pCnt;
}


int main(int argc, char **argv)
{
    int in;
    
//    freopen("sample_input.txt", "r", stdin);
    
 //   cin >> tc;
    
 //   for (it=0 ; it < tc ; it++)
    {
        cin >> n;
        cin >> m;
        mapSize = n*m;
   //     cout << n << endl;
   //     cout << m << endl;
        for (in=1 ; in <= n ; in++)
        {
            cin >> &map[in][1];
    //        cout << &map[in][1] << endl; 
        }
    
        
        find_solution();
    }
    
    return 0;    

}