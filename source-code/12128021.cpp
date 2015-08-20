//Language: GNU C++11


#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
#define maxn 412345
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;


int n,m;
int data[26][maxn], mark[26][maxn];
void init(int _n){
	n=1;
	while(n<_n)n<<=1;
	memset(data,0,sizeof(data));
	memset(mark,-1,sizeof(mark));
}

void push_down(int k,int l,int r,int num){
	if(~mark[num][k]){
		int val=mark[num][k];
		mark[num][2*k+1]=val;
		mark[num][2*k+2]=val;
		int mid=l+r>>1;
		data[num][2*k+1]=val*(mid-l);
		data[num][2*k+2]=val*(mid-l);
		mark[num][k]=-1;
	}
}

//ʹĳ����䶼��Ϊ0��1  
void update(int nl,int nr,int k,int l,int r,int num,int val){
	if(nl<=l && nr>=r){
		data[num][k]=(r-l)*val;
		mark[num][k]=val;
		return ;	
	}
	if(nl>=r || nr<=l)return ;
	push_down(k,l,r,num);
	int mid=l+r>>1;
	update(nl,nr,2*k+1,l,mid,num,val);
	update(nl,nr,2*k+2,mid,r,num,val);
	data[num][k]=data[num][2*k+1]+data[num][2*k+2];
}

int getsum(int nl,int nr,int k,int l,int r,int num){
	if(nl<=l && nr>=r) return data[num][k];
	if(nl>=r ||nr<=l)return 0;
	push_down(k,l,r,num);
	int temp=0;
	int mid=l+r>>1;
	temp+=getsum(nl,nr,k*2+1,l,mid,num);
	temp+=getsum(nl,nr,k*2+2,mid,r,num);
	return temp;
}
int cnt[27];
void modifyup(int nl,int nr,int k,int l,int r){
	for(int i=0;i<26;++i){
		cnt[i]=getsum(nl,nr,k,l,r,i);
	}
	for(int i=0;i<26;++i){
		update(nl,nr,0,l,r,i,0);
	}
	for(int i=0;i<26;++i){
	//	cout<<"98: "<<i<<endl;
		update(nl,nl+cnt[i],k,l,r,i,1);
		nl+=cnt[i];
	}
}
void modifydown(int nl,int nr,int k,int l,int r){
	for(int i=0;i<26;++i){
		cnt[i]=getsum(nl,nr,k,l,r,i);
	}
	for(int i=0;i<26;++i){
		update(nl,nr,0,l,r,i,0);
	}
	for(int i=25;i>=0;--i){
		//cout<<"111: "<<i<<endl;
		update(nl,nl+cnt[i],k,l,r,i,1);
		nl+=cnt[i];
	}
}

char str[maxn];
int main()
{_
	int xn;
	cin>>n>>m>>str;xn=n;
	init(n);
	for(int i=0;i<xn;++i){
		update(i,i+1,0,0,n,str[i]-'a',1);
	}
	int l,r,sign;
	
	while(m--){
		cin>>l>>r>>sign;
		if(sign==1)
			modifyup(l-1,r,0,0,n);
		else 
			modifydown(l-1,r,0,0,n);
	}
	
	for(int i=0;i<xn;++i){
		for(int j=0;j<26;++j){
			if(getsum(i,i+1,0,0,n,j)){
				cout<<char(j+'a');
				break;
			}
		}
	}
	cout<<endl;
	

	return 0;
}



