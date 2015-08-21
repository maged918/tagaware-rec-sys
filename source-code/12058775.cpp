//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define PII pair <int, int> 
int freq [8*100005][28];
int lazyz [8*100005][28];
int lazya [8*100005][28]; 
int storefreq [28]; 
void insert (int start, int end, int i, int node, int seg)
{
    if (start>i || end<i) return;
    if (start==end)
    {freq[node][seg]++; return;}
    insert(start, (start+end)/2, i, 2*node, seg);
    insert((start+end)/2+1, end, i, 2*node+1, seg); 
    freq[node][seg]=freq[2*node][seg]+freq[2*node+1][seg]; 
} 
void pushz(int node, int seg)
{
    if (lazyz[node][seg])
    {
        freq[node][seg] = 0;
        lazyz[2*node][seg]=lazyz[node][seg]; 
        lazya[2*node][seg]=0; lazya[2*node+1][seg]=0;
        lazyz[2*node+1][seg]=lazyz[node][seg];
        lazyz[node][seg] = 0; 
    }
}
void pusha (int start, int end, int node, int seg)
{
    if (lazya[node][seg])
    {
        freq[node][seg]+=(end-start+1)*lazya[node][seg]; 
        lazya[2*node][seg]+=lazya[node][seg]; 
        lazya[2*node+1][seg]+=lazya[node][seg]; 
        lazya[node][seg]=0;     
    }
}
void zeroout (int start, int end, int i, int j, int node, int seg)
{
    pushz(node, seg); 
    if (start!=end)pushz(2*node, seg), pushz (2*node+1, seg);
    pusha(start, end, node, seg); 
    if (start>j || end<i) return; 
    if (start>=i && end<=j)
    {
        lazyz[node][seg] = 1; 
        pushz(node, seg); 
        return; 
    }
    zeroout (start, (start+end)/2, i, j, 2*node, seg); 
    zeroout ((start+end)/2+1, end, i, j, 2*node+1, seg); 
    freq[node][seg]=freq[2*node][seg]+freq[2*node+1][seg]; 
}
void update (int start, int end, int i, int j, int node, int seg)
{
    pushz(node, seg);
    if (start!=end)pushz(2*node, seg), pushz (2*node+1, seg);
    pusha(start, end, node, seg);
    if (start>j || end<i) return; 
    if (start>=i && end<=j)
    {
        lazya[node][seg]++; 
        pusha(start, end, node, seg); 
        return; 
    }
    update (start, (start+end)/2, i, j, 2*node, seg); 
    update ((start+end)/2+1, end, i, j, 2*node+1, seg); 
    freq[node][seg]=freq[2*node][seg]+freq[2*node+1][seg]; 
}
int query (int start, int end, int i, int j, int node, int seg)
{if(start>j ||end<i) return 0;
    pushz(node, seg);
    if (start!=end)pushz(2*node, seg), pushz (2*node+1, seg);
    pusha(start, end, node, seg); 
    if (start>=i && end<=j) return freq[node][seg]; 
    return query(start, (start+end)/2, i, j, 2*node, seg)+query((start+end)/2+1, end, i, j, 2*node+1, seg); 
}
int main()
{
    ios_base::sync_with_stdio(0); 
    int leng, Q; cin >> leng >> Q; 
    string S; cin >> S;
    for (int g=0; g<S.length(); g++) insert(0, leng-1, g, 1, S[g]-'a');
    for (int g=0; g<Q; g++)
    {
        int i, j, k; cin >> i >> j >> k; 
        i--, j--;
        memset(storefreq, 0, sizeof(storefreq));
        for (int y=0; y<26; y++)
        {
            storefreq[y] = query(0, leng-1, i, j, 1, y);
            zeroout (0, leng-1, i, j, 1, y);  
        }
        int curi = i; 
        if (k)
        {
            for (int y=0; y<26; y++)
            {
                if (storefreq[y]==0)continue;
                update (0, leng-1, curi, curi+storefreq[y]-1, 1, y); 
                curi+=storefreq[y]; 
            }
        }
        else
        {
            for (int y=25; y>=0; y--)
            {if (storefreq[y]==0)continue;
                update (0, leng-1, curi, curi+storefreq[y]-1, 1, y); 
                curi+=storefreq[y]; 
            }
        }
    }
    for (int g=0; g<leng; g++)
    {
        for (int y=0; y<26; y++)
        {
            if (query(0, leng-1, g, g, 1, y))putchar((char)('a'+y));
        }
    }
    return 0;
}