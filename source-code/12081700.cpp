//Language: GNU C++11


#include<stdio.h>
#define S 100100
#define INF (1<<30)
int Pre(int x,int y)
{
	if(x>y)
		return Pre(x/2,y);
	else if(x<y)
		return Pre(x,y/2);
	return x;
}
int main()
{
	int n,a[S],i,j,ans=INF,s,pre,flag,p,w1,w2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>2)
			pre=Pre(pre,a[i]);
		else if(i==2)
			pre=Pre(a[1],a[2]);
		else if(i==1)
			pre=a[1];
	}
	//printf("%d\n",pre);
	for(p=pre;pre<=100000;pre*=2)
	{
		for(i=1,s=0;i<=n;i++)
		{
			w1=a[i];
			w2=p;
			while(w2*2<=w1)	w2*=2;
			while(w2^w1) {w2/=2;w1/=2;s++;}
			while(w1!=pre)
			{
				if(w1<pre)
					w1*=2;
				else 
					w1/=2;
				s++;
			}
		}
		//printf("%d\n",s);
		ans=ans<s?ans:s;
	}
	printf("%d\n",ans);
	return 0;
}
