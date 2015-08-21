//Language: GNU C++


/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define MAXN 100010
using namespace std;

bool isNumed[MAXN];
bool isUsed[MAXN];
int items[MAXN];

int main()
{
    memset(isUsed, false, sizeof(isUsed));
    memset(isNumed, false, sizeof(isUsed));

    int n;  cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d", &items[i]);

        int now=items[i];
        if(now<=n&&!isNumed[now]){
            isNumed[now]=true;
            isUsed[i]=true;
        }
    }

    for(int now=1;now<=n;now++){
        if(!isNumed[now]){
            int i=0;
            while(isUsed[i]) i++;
            items[i]=now;
            isUsed[i]=true;
            isNumed[now]=true;
        }
    }

    int i;
    for(i=0;i<n-1;i++){
        printf("%d ", items[i]);
    }
    printf("%d\n", items[i]);
    return 0;
}
*/

#include <iostream>
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
using namespace std;
const int N = 100005;
int a[N];
bool b[N];  //��ǰֵ�Ƿ����
bool c[N];  //��ǰ���ֵ�Ƿ��ظ�
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,false,sizeof(b));
        memset(c,false,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(b[a[i]]==false&&a[i]<=n)
            //���ڸ�����Χ�ڵĵ�һ�γ��ֵ������ǲ��޸�
                b[a[i]]=true;
            //����Ҫ�޸�
            else c[i]=true;
        }
        int tt=1;
        for(int i=1;i<=n;i++)
        {
            //����ÿ��Ҫ�޸ĵĵ�
            if(c[i]==true)
            {
                //�ҵ�û�г��ֵ�Ԫ��
                while(b[tt])    tt++;
                //ȥ�滻a[i]��ֵ
                a[i]=tt;
                //������Ԫ�ر��Ϊ���ֹ�
                b[tt]=true;
            }
        }
        for(int i=1;i<n;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }

    return 0;
}
