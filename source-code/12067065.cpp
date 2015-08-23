//Language: GNU C++


#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxc=26;
const int maxn=100005;
const int maxt=300005;
inline void _getnum(int &xx)
{
    char tt=getchar();
    while(tt<'0'||tt>'9')tt=getchar();
    for(xx=0;tt>='0'&&tt<='9';tt=getchar())xx=xx*10+(tt-'0');
}
int N,M,cnt[maxc];
char str[maxn];
struct splay_node
{
    char ch;
    int c,count;
    int ls,rs,fath;
}p[maxt],null_node;
int tot_node,Z_rib[maxn],Z_top;
int _new_splay_node()
{
    if(Z_top>0)return Z_rib[--Z_top];
    else return ++tot_node;
}
void _recycle_splay_node(int i)
{
    p[i]=null_node;
    Z_rib[Z_top++]=i;
}
void _pushup(int i)
{
    p[i].count=p[i].c+p[p[i].ls].count+p[p[i].rs].count;
}
struct splay_tree
{
    int root;
    void _build(int &i,int l,int r)
    {
        i=(l+r)>>1;
        if(i==0)
        {
            i=N+2;
            p[i].c=1;
            if(0<r)_build(p[i].rs,1,r),p[p[i].rs].fath=i;
        }
        else
        {
            p[i].ch=str[i];
            p[i].c=1;
            if(l<i)_build(p[i].ls,l,i-1),p[p[i].ls].fath=i;
            if(i<r)_build(p[i].rs,i+1,r),p[p[i].rs].fath=i;
        }
        _pushup(i);
    }
    void _build()
    {
        _build(root,0,N+1);
        tot_node=N+2;
    }
    void _zig(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(root==j)root=i;
        else if(j==p[k].ls)p[k].ls=i;
        else p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].rs].fath=j;
        p[j].ls=p[i].rs;
        p[i].rs=j;
        p[i].count=p[j].count;
        _pushup(j);
    }
    void _zag(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(root==j)root=i;
        else if(j==p[k].ls)p[k].ls=i;
        else p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].ls].fath=j;
        p[j].rs=p[i].ls;
        p[i].ls=j;
        p[i].count=p[j].count;
        _pushup(j);
    }
    void _splay(int i)
    {
        int j;
        while(i!=root)
        {
            j=p[i].fath;
            if(j==root||p[j].fath==root)
            {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            }
            else if(j==p[p[j].fath].ls)
            {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            }
            else 
            {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_node(int x)
    {
        int i=root;
        /*
        if(x==0)
        {
            for(;p[i].ls!=0;i=p[i].ls);
            return i;
        }
        */
        while(i!=0)
        {
            if(x<=p[p[i].ls].count)i=p[i].ls;
            else if(x<=p[p[i].ls].count+p[i].c)return i;
            else x-=p[p[i].ls].count+p[i].c,i=p[i].rs;
        }
        return -1;
    }
    int _find_left_node(int i)
    {
        _splay(i);
        for(i=p[i].ls;p[i].rs!=0;i=p[i].rs);
        return i;
    }
    int _find_right_node(int i)
    {
        _splay(i);
        for(i=p[i].rs;p[i].ls!=0;i=p[i].ls);
        return i;
    }
    void _insert(int j,int x)
    {
        int i=root;
        if(i==0)
        {
            root=j;
            return;
        }
        while(i!=0)
        {
            p[i].count+=p[j].count;
            if(x<=p[p[i].ls].count)
            {
                if(p[i].ls!=0)
                    i=p[i].ls;
                else 
                {
                    p[i].ls=j;
                    p[j].fath=i;
                    _splay(j);
                    return;
                }
            }
            else
            {
                x-=p[p[i].ls].count+p[i].c;
                if(p[i].rs!=0)
                    i=p[i].rs;
                else
                {
                    p[i].rs=j;
                    p[j].fath=i;
                    _splay(j);
                    return;
                }
            }
        }
    }
    void _dfs_recycle(int i)
    {
        if(p[i].ls!=0)_dfs_recycle(p[i].ls);
        if(p[i].rs!=0)_dfs_recycle(p[i].rs);
        cnt[p[i].ch-'a']+=p[i].c;
        _recycle_splay_node(i);
    }
    void _output_dfs(int i)
    {
        if(p[i].ls!=0)_output_dfs(p[i].ls);
        
        if(i!=N+1&&i!=N+2)
            for(int j=1;j<=p[i].c;j++)
                putchar(p[i].ch);
        
        /*
        printf("p[%2d]  ",i);
        printf("ch=%c  ",p[i].ch);
        printf("c=%d  ",p[i].c);
        printf("count=%d  ",p[i].count);
        printf("ls=%d  ",p[i].ls);
        printf("rs=%d\n",p[i].rs);
        */
        if(p[i].rs!=0)_output_dfs(p[i].rs);
    }
    void _output()
    {
        _output_dfs(root);
    }
}T,T1,T2;
void _split(splay_tree &A,int x,splay_tree &B)
{
    int i,j,k,t,cl;
    x++;
    i=A._find_node(x);
    A._splay(i);
    cl=p[p[i].ls].count;
    if(cl+p[i].c==x)
        j=A._find_right_node(i);
    else
    {
        j=_new_splay_node();
        p[j].ch=p[i].ch;
        p[j].c=cl+p[i].c-x;
        p[j].count=p[j].c;
        p[i].c-=p[j].c;
        _pushup(i);
        A._insert(j,x);
        
    }
    
    A._splay(j);
    A._splay(i);
    p[i].rs=0;
    p[j].fath=0;
    _pushup(i);
    B.root=j;
}
void _rebuild(splay_tree &A,int ty)
{
    int i,j,k,t,n;
    for(j=0;j<26;j++)cnt[j]=0;
    A._dfs_recycle(A.root);
    A.root=0;
    n=0;
    if(ty==1)
    {
        for(j=0;j<26;j++)
        {
            if(cnt[j]==0)continue;
            i=_new_splay_node();
            p[i].ch=j+'a';
            p[i].c=cnt[j];
            p[i].count=p[i].c;
            A._insert(i,n);
            n+=cnt[j];
        }
    }
    else
    {
        for(j=25;j>=0;j--)
        {
            if(cnt[j]==0)continue;
            i=_new_splay_node();
            p[i].ch=j+'a';
            p[i].c=cnt[j];
            p[i].count=p[i].c;
            A._insert(i,n);
            n+=cnt[j];
        }
    }
}
void _merge(splay_tree &A,splay_tree &B)
{
    int i,j,k,t;
    i=B.root;
    B.root=0;
    t=p[A.root].count;
    A._insert(i,t);
}
void _debug()
{
    printf("T::\n");
    T._output();
    printf("\n");
    
    printf("T1::\n");
    T1._output();
    printf("\n");
    
    printf("T2::\n");
    T2._output();
    printf("\n");
    
    printf("\n");
}
int main()
{
    //freopen("datax.in","r",stdin);
    int i,j,k,t,l,r;
    _getnum(N);_getnum(M);
    scanf("%s",str+1);
    T._build();
    /*
    _debug();
    */
    for(i=1;i<=M;i++)
    {
        _getnum(l);_getnum(r);_getnum(k);
        /*
        printf("%d :: %d %d %d\n",i,l,r,k);
        if(i==6)
        {
            _debug();
        }
        */
        _split(T,r,T2);
        /*
        if(i==6)
        {
            _debug();
        }
        */
        _split(T,l-1,T1);
        /*
        if(i==6)
        {
            _debug();
        }
        */
        _rebuild(T1,k);
        /*
        if(i==6)
        {
            _debug();
        }
        */
        _merge(T1,T2);
        /*
        if(i==6)
        {
            _debug();
        }
        */
        _merge(T,T1);
        /*
        _debug();
        j=0;
        */
    }
    T._output();
    return 0;
}
