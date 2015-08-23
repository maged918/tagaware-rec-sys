//Language: GNU C++


#include<stdio.h>
#include<string.h>
const int maxn=100000+10;
char s[maxn];
int sumv[26][4*maxn];
int tag[26][4*maxn];
int cnt[26];
void build(int lab,int root,int l,int r)
{
	if (l==r)
	{
		if (s[l-1]=='a'+lab) sumv[lab][root]=1;
		else sumv[lab][root]=0;
		tag[lab][root]=-1;
		return;
	}
	int mid=(l+r)>>1;
	build(lab,root<<1,l,mid);
	build(lab,(root<<1)+1,mid+1,r);
	sumv[lab][root]=sumv[lab][root<<1]+sumv[lab][(root<<1)+1];
	tag[lab][root]=-1;
}
int query(int lab,int root,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr) return sumv[lab][root];
	int mid=(l+r)>>1;
	if (tag[lab][root]!=-1)
	{
		sumv[lab][root<<1]=tag[lab][root]*(mid-l+1);
		sumv[lab][(root<<1)+1]=tag[lab][root]*(r-mid);
		tag[lab][root<<1]=tag[lab][root];
		tag[lab][(root<<1)+1]=tag[lab][root];
		tag[lab][root]=-1;
	}
	if (rr<=mid) return query(lab,root<<1,l,mid,ll,rr);
	if (ll>mid) return query(lab,(root<<1)+1,mid+1,r,ll,rr);
	int ans=0;
	ans+=query(lab,root<<1,l,mid,ll,rr);
	ans+=query(lab,(root<<1)+1,mid+1,r,ll,rr);
	return ans;
}
void update(int lab,int root,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr)
	{
		tag[lab][root]=1;
		sumv[lab][root]=r-l+1;
		return;
	}
	int mid=(l+r)>>1;
	if (tag[lab][root]!=-1)
	{
		sumv[lab][root<<1]=tag[lab][root]*(mid-l+1);
		sumv[lab][(root<<1)+1]=tag[lab][root]*(r-mid);
		tag[lab][root<<1]=tag[lab][root];
		tag[lab][(root<<1)+1]=tag[lab][root];
		tag[lab][root]=-1;
	}
	if (rr<=mid) update(lab,root<<1,l,mid,ll,rr);
	else if (ll>mid) update(lab,(root<<1)+1,mid+1,r,ll,rr);
	else
	{
		update(lab,root<<1,l,mid,ll,rr);
		update(lab,(root<<1)+1,mid+1,r,ll,rr);
	}
	sumv[lab][root]=sumv[lab][root<<1]+sumv[lab][(root<<1)+1];
}
void clear(int lab,int root,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr)
	{
		tag[lab][root]=0;
		sumv[lab][root]=0;
		return;
	}
	int mid=(l+r)>>1;
	if (tag[lab][root]!=-1)
	{
		sumv[lab][root<<1]=tag[lab][root]*(mid-l+1);
		sumv[lab][(root<<1)+1]=tag[lab][root]*(r-mid);
		tag[lab][root<<1]=tag[lab][root];
		tag[lab][(root<<1)+1]=tag[lab][root];
		tag[lab][root]=-1;
	}
	if (rr<=mid) clear(lab,root<<1,l,mid,ll,rr);
	else if (ll>mid) clear(lab,(root<<1)+1,mid+1,r,ll,rr);
	else
	{
		clear(lab,root<<1,l,mid,ll,rr);
		clear(lab,(root<<1)+1,mid+1,r,ll,rr);
	}
	sumv[lab][root]=sumv[lab][root<<1]+sumv[lab][(root<<1)+1];
}
int main()
{
	//freopen("558E.in","r",stdin);
	//freopen("558E.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%s",s);
	for (int i=0;i<26;i++)
	build(i,1,1,n);
	for (int i=1;i<=q;i++)
	{
		int ll,rr,t;
		scanf("%d%d%d",&ll,&rr,&t);
		memset(cnt,0,sizeof(cnt));
		for (int j=0;j<26;j++)
		{
			cnt[j]=query(j,1,1,n,ll,rr);
			clear(j,1,1,n,ll,rr);
		}
		if (t==0)
		{
			int p=rr;
			for (int j=0;j<26;j++)
			{
				if (cnt[j]) update(j,1,1,n,p-cnt[j]+1,p);
				p-=cnt[j];
			}
		}
		else
		{
			int p=ll;
			for (int j=0;j<26;j++)
			{
				if (cnt[j]) update(j,1,1,n,p,p+cnt[j]-1);
				p+=cnt[j];
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<26;j++)
		if (query(j,1,1,n,i,i)==1)
		{
			printf("%c",'a'+j);
			break;
		}
	}
	printf("\n");
	return 0;
}