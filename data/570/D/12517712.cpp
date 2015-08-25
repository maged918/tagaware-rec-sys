//Language: GNU C++11


#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;

vector<vector<int> > niz;
vector<vector<int> > ve,niz2;
vector<int> dub,maxc,idj;
int n,m,id=0;
char s[500005];

int dfsre(int x)
{
    idj[x]=id++;
    niz[dub[x]].pb(1<<(s[x]-'a'));
    niz2[dub[x]].pb(idj[x]);
    int last=idj[x];
    for(int i=0;i<ve[x].size();i++)
        last=dfsre(ve[x][i]);
    return maxc[x]=last;
}

int main()
{
   // memset(niz,0,sizeof niz);
    scanf("%d %d",&n,&m);
    dub.resize(n);ve.resize(n);
    maxc.resize(n);idj.resize(n);
    dub[0]=1;
    int maxd=1,a,b;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a);
        a--;
        ve[a].pb(i);
        dub[i]=dub[a]+1;
        maxd=max(dub[i],maxd);
    }
    scanf(" %s",s);
    niz.resize(maxd+1);
    niz2.resize(maxd+1);
    for(int j=0;j<maxd+1;j++)
        niz[j].pb(0);
    dfsre(0);
    for(int j=0;j<maxd+1;j++)
    for(int k=1;k<niz[j].size();k++)
        niz[j][k]=(niz[j][k-1]^niz[j][k]);
//    for(int i=0;i<maxd+1;i++)
//    {
//        printf("Dubina %d:\n",i);
//        for(int j=0;j<27;j++)
//        {
//            printf("Slovo %c: ",j+'a');
//            for(int k=0;k<niz[j][i].size();k++)
//            printf("%d ",niz[j][i][k]);
//            puts("");
//        }
//
//    }
    while(m--)
    {
        scanf("%d %d",&a,&b);
        if(b>maxd){printf("Yes\n");continue;}
        a--;
        int poc=idj[a],kraj=maxc[a];

       // printf("poc :%d kraj :%d\n",poc,kraj);

        vector<int> &x(niz2[b]);
        poc=lower_bound(x.begin(),x.end(),poc)-x.begin();
        kraj=upper_bound(x.begin(),x.end(),kraj)-x.begin();
        int brnp=0,z=0;
        brnp=(niz[b][kraj]^niz[b][poc]);
        for(int i=0;i<26;i++)if(brnp&(1<<i))z++;
        printf("%s\n",(z>1)?"No":"Yes");
    }
    return 0;
}

