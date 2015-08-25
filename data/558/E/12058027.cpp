//Language: GNU C++11



#include<bits/stdc++.h>
//#include <windows.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define sqr(x)      ((x)*(x))
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define pf          printf
#define VI          vector <int>
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define mp          make_pair
#define pi          acos(-1.00)
#define DBG         pf("Hi\n")
#define sz          size()
#define ins         insert
#define fi          first
#define se          second
#define xx          first
#define yy          second
#define inf         (1<<29)
#define hp          (LL) 999983
#define MOD         100007
#define eps         1e-9
#define MAX         100000

typedef long long int LL;
typedef double db;

//int dx[] = {+0,+1,+0,-1};
//int dy[] = {+1,+0,-1,+0};
//int dx[] = {-1,-1,-1,+0,+0,+1,+1,+1};
//int dy[] = {-1,+0,+1,-1,+1,-1,+0,+1};
//bool check(LL n, int pos) {return (bool) (n & ((LL)1<<pos));}
//LL on(LL n, int pos) {return n | ((LL)1<<pos); }
//LL off(LL n, int pos) {return n & ~((LL)1<<pos); }

#define scale(x)    (x-'a')

int n;
char str[MAX+10];
int cnt[30];

struct node{
    int sum, setflag;
}tree[30][4*MAX];

void prop(int idx, int ch, int st, int ed, int tp)
{
    tree[ch][idx].setflag = tp;
    if(tp == 1) tree[ch][idx].sum = (ed-st+1);
    else tree[ch][idx].sum = 0;
    return;
}

void update(int idx, int ch, int st, int ed, int i, int j, int tp)
{
    if(st == i && ed == j)
    {
        tree[ch][idx].setflag = tp;
        if(tp == 1) tree[ch][idx].sum = (ed-st+1);
        else tree[ch][idx].sum = 0;

        return;
    }

    int l = 2*idx, r = l|1, mid = (st+ed)/2;
    if(tree[ch][idx].setflag)
    {
        prop(l,ch,st,mid,tree[ch][idx].setflag);
        prop(r,ch,mid+1,ed,tree[ch][idx].setflag);

        tree[ch][idx].setflag = 0;
    }

    if(j <= mid) update(l,ch,st,mid,i,j,tp);
    else if(i > mid) update(r,ch,mid+1,ed,i,j,tp);
    else update(l,ch,st,mid,i,mid,tp), update(r,ch,mid+1,ed,mid+1,j,tp);

    tree[ch][idx].sum = tree[ch][l].sum + tree[ch][r].sum;
}

int query(int idx, int ch, int st, int ed, int i, int j)
{
    if(st == i && ed == j) return tree[ch][idx].sum;

    int l = 2*idx, r = l|1, mid = (st+ed)/2;
    if(tree[ch][idx].setflag)
    {
        prop(l,ch,st,mid,tree[ch][idx].setflag);
        prop(r,ch,mid+1,ed,tree[ch][idx].setflag);

        tree[ch][idx].setflag = 0;
    }
    if(j <= mid) return query(l,ch,st,mid,i,j);
    else if(i > mid) return query(r,ch,mid+1,ed,i,j);
    else return query(l,ch,st,mid,i,mid) + query(r,ch,mid+1,ed,mid+1,j);
}

int main()
{
    //freopen("c:\\Users\\User\\Desktop\\in.txt", "r", stdin);
    //freopen("c:\\Users\\User\\Desktop\\out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int i, j, k, t, cs, q, mn, mx, l, r, csm;

    scanf("%d %d", &n, &q);
    scanf("%s", str);

    for(i = 0; i < n; i++)
        update(1,scale(str[i]),0,n,i,i,1);

    while(q--)
    {
        scanf("%d %d %d", &l, &r, &k);
        l--, r--;

        for(i = 0; i <= 25; i++)
            cnt[i] = query(1,i,0,n,l,r);

        for(i = 0; i <= 25; i++)
            update(1,i,0,n,l,r,-1);

        csm = l;
        if(k)
        {
            for(i = 0; i <= 25; i++)
                if(cnt[i])
                {
                    update(1,i,0,n,csm,csm+cnt[i]-1,1);
                    csm += cnt[i];
                }
        }

        else
        {
            for(i = 25; i >= 0; i--)
                if(cnt[i])
                {
                    update(1,i,0,n,csm,csm+cnt[i]-1,1);
                    csm += cnt[i];
                }
        }

        /*for(i = 0; i < n; i++)
        for(j = 0; j <= 25; j++)
            if(query(1,j,0,n,i,i))
            {
                printf("%c", j+'a');
                break;
            }*/
    }


    for(i = 0; i < n; i++)
        for(j = 0; j <= 25; j++)
            if(query(1,j,0,n,i,i))
            {
                printf("%c", j+'a');
                break;
            }

    return 0;
}


