//Language: GNU C++11


#include <bits/stdc++.h> 

#define ll long long
#define md 1000000007LL
#define EPS 0.000000000001

const int MAXN = 100005;

using namespace std;

char buf[100001];

class Tree 
{

public:
    struct elem 
    {
        int v, d, k;

        elem() 
        {
            v = 0, d = 0, k = 0;
        }
    };

    vector<elem> tree;

    Tree() 
    {
        tree = vector<elem> (4 * MAXN, elem());
    };

    void push_down(int id, int l, int r) 
    {
        if (l > r) 
        {
            return;
        }

        if (l != r && tree[id].d != -1) 
        {
            tree[id + id].d = tree[id].d;
            tree[id + id + 1].d = tree[id].d;
            tree[id].v = tree[id].d * tree[id].k;
            tree[id].d = -1;
            return;
        }

        if (l == r && tree[id].d != -1)  
        {
            tree[id].v = tree[id].d;
            tree[id].d = -1;
            return;
        }

        return;
    }


    void modify(int id, int l, int r, int a, int b, int v) 
    {
        if (b < l || a > r || l > r) 
        {
            return; 
        }
        
        push_down(id, l, r);
        //printf("id = %d l = %d r = %d a = %d b = %d\n", id, l, r, a, b);

        if (a <= l && b >= r) 
        {
            tree[id].v = v * tree[id].k;
            tree[id].d = -1;
        
            if (l != r) 
            {
                tree[id + id].d = v;
                tree[id + id + 1].d = v;
            }
            
            return;
        }

        int mid = (l + r) / 2;
        modify(id + id, l, mid, a, b, v);
        modify(id + id + 1, mid + 1, r, a, b, v);

        push_down(id + id, l, mid);
        push_down(id + id + 1, mid + 1, r);

        tree[id].v = tree[id + id].v + tree[id + id + 1].v;
        tree[id].d = -1;
    }


    int getsum(int id, int l, int r, int a, int b) 
    {
        if (b < l || a > r || l > r) 
        {
            return 0;
        }

        if (a <= l && b >= r) 
        {
            push_down(id, l, r);
            return tree[id].v;
        }

        int mid = (l + r) / 2;
        push_down(id, l, r);

        return getsum(id + id, l, mid, a, b) + getsum(id + id + 1, mid + 1, r, a, b);
    }


    void CreateTree(int id, int l, int r) 
    {
       if (l > r) 
       {
           return;
       }

       if (l == r) 
       {
           tree[id].v = 0;
           tree[id].d = -1;
           tree[id].k = 1;
           return;
       }
        
       int mid = (l + r) / 2;

       CreateTree(id + id, l, mid);
       CreateTree(id + id + 1, mid + 1, r);

       tree[id].v = 0;
       tree[id].d = 0;
       tree[id].k = tree[id + id].k + tree[id + id + 1].k;
    }

};


Tree letters[26];


void show(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 26; j++) 
        {
            if (letters[j].getsum(1, 1, n, i + 1, i + 1)) 
            {
                printf("%c", (char)j + 'a');
                break;
            }
        }
    }

    printf("\n");
}



int main()
{
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
    #endif //DEBUG
        
    int n, q;
    scanf("%d %d\n", &n, &q);

    gets(buf);

    for (int i = 0; i < 26; i++) 
    {
        letters[i].CreateTree(1, 1, n);
    }
    
    for (int i = 0; i < n; i++) 
    {
        letters[buf[i] - 'a'].modify(1, 1, n, i + 1, i + 1, 1);
    }


    for (int i = 0; i < q; i++) 
    {
        int l, r, k;
        scanf("%d %d %d\n", &l, &r, &k);
        
        int letters_count[26];
        for (int i = 0; i < 26; i++) 
        {
            letters_count[i] = letters[i].getsum(1, 1, n, l, r);
            letters[i].modify(1, 1, n, l, r, 0);
        }

        int cur = l;
        if (k) 
        {
            for (int i = 0; i < 26; i++) 
            {
                letters[i].modify(1, 1, n, cur, cur + letters_count[i] - 1, 1);
                cur += letters_count[i];
            }
        } else 
        {
            for (int i = 25; i >= 0; i--) 
            {
                letters[i].modify(1, 1, n, cur, cur + letters_count[i] - 1, 1);
                cur += letters_count[i];
            }
        }
    }

    show(n);

    fprintf(stderr, "Execution time = %.4lfsec", (double)clock() / (double)CLOCKS_PER_SEC);    
    return 0;
}
