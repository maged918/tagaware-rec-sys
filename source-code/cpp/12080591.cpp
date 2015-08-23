//Language: GNU C++11


#include <bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define mid (l+r)/2
#define N 100005

using namespace std;

int n,q,u;
int t[27][4*N],f[27][4*N];
string s;

void build(int j, int k, int l, int r) {
    f[j][k]=-1;
    if (l==r) { t[j][k]=(int(s[l]-'a')==j); return; }
    build(j,2*k,l,mid); build(j,2*k+1,mid+1,r);
    t[j][k]=t[j][2*k]+t[j][2*k+1];
}

void lazy(int j, int k, int l, int r) {
    if (f[j][k]!=-1) {
        t[j][k]=(r-l+1)*f[j][k];
        if (l!=r) f[j][2*k]=f[j][2*k+1]=f[j][k];
        f[j][k]=-1;
    }
}

int sum(int j, int k, int l, int r, int p, int q) {
    lazy(j,k,l,r);
    if (r<p || l>q) return 0;
    if (p<=l && r<=q) return t[j][k];
    return ( sum(j,2*k,l,mid,p,q)+sum(j,2*k+1,mid+1,r,p,q) );
}

void upd(int j, int k, int l, int r, int p, int q) {
    lazy(j,k,l,r);
    if (l>q || r<p) return;
    if (p<=l && r<=q) {
        t[j][k]=(r-l+1)*u;
        if (l!=r) f[j][2*k]=f[j][2*k+1]=u;
        return;
    }
    upd(j,2*k,l,mid,p,q);   upd(j,2*k+1,mid+1,r,p,q);
    t[j][k]=t[j][2*k]+t[j][2*k+1];
}

void ans(int j, int k, int l, int r) {
    lazy(j,k,l,r);
    if (t[j][k]==0) return;
    if (l==r) { s[l]='a'+j; return; }
    ans(j,2*k,l,mid); ans(j,2*k+1,mid+1,r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("a.txt","r",stdin);
    //freopen("a.ttt","w",stdout);
    cin>>n>>q; getline(cin,s,'\n');
    getline(cin,s,'\n');
    s='0'+s;
    fu(i,0,25) build(i,1,1,n);
    int sl[27];
    fu(i,1,q) {
        int l,r,k,trc; cin>>l>>r>>k; u=0;
        fu(j,0,25) {
            sl[j]=sum(j,1,1,n,l,r);
            if (sl[j]!=0) upd(j,1,1,n,l,r);
        }
        u=1; trc=l;
        if (k==1) {
            fu(j,0,25) if (sl[j]!=0) {
                upd(j,1,1,n,trc,trc+sl[j]-1);
                trc+=sl[j];
            }
        } else {
            fd(j,25,0) if (sl[j]!=0) {
                upd(j,1,1,n,trc,trc+sl[j]-1);
                trc+=sl[j];
            }
        }
    }
    fu(i,0,25) ans(i,1,1,n);
    s.erase(0,1);
    cout<<s;
}
