//Language: GNU C++11


#include <bits/stdc++.h>
#define Max 100009
#define N 29

using namespace std;
int n=0,q;

int arr[N][Max*4];
int lazy[N][Max*4];

char s[Max];

void build( int l , int r , int node , int v){
	if( l == r ){
		if( s[l-1] == char(v + 'a') )
			arr[v][node] = 1;
		return;
	}
	int mid=( l + r )/2;
	build(l,mid,node*2,v);
	build(mid+1,r,node*2+1,v);
	arr[v][node] = arr[v][node*2] + arr[v][node*2+1];
}
void shift( int l , int mid , int r , int node , int v){
	
	if(lazy[v][node] != -1 ){
		int c=lazy[v][node];
		lazy[v][node]=-1;
		
		lazy[v][node*2]=	c;
		lazy[v][node*2+1]=	c;
		
		arr[v][node*2] = (mid-l+1) * c;
		arr[v][node*2+1] = (r - mid) * c;
	}
}
void upd( int l , int r , int node , int ll ,int rr , int v, int z){
	
	if( ll <= l && r <= rr ){
		lazy[v][node] = z;
		arr[v][node] = ( r - l + 1 ) * z;
		return;	
	}
	if( l > rr || r < ll )
		return;
	shift(l,(l+r)/2,r,node,v);
	
	int mid=(l + r )/2;
	
	upd(l , mid ,node*2,ll,rr,v,z);
	upd(mid+1 , r ,node*2+1,ll,rr,v,z);
	arr[v][node] = arr[v][node*2] + arr[v][node*2+1];	
}
int find( int l , int r , int node , int ll, int rr , int v){
	
	if( ll <= l && r <= rr  ){
		return arr[v][node];	
	}
	if( l > rr || r < ll )
		return 0;
		
	shift(l,(l+r)/2,r,node,v);
	int mid=( l + r )/2;
	
	return ( find( l , mid , node*2 , ll , rr , v ) +  find( mid + 1 , r , node*2+1 , ll , rr , v ));
}
int num[N];

int main(){
	
	scanf("%d%d",&n,&q);
	scanf("%s" ,s);
	
	int a,b,c;
	memset( lazy , -1 , sizeof(lazy));
	
	for( int i=0;i<26;i++)
		build(1,n,1,i);
		
	for( int i=0;i<q;i++){
		scanf("%d%d%d",&a,&b,&c);
		for( int j=0;j<26;j++){
			num[j]=find(1,n,1,a,b,j);	
			upd(1,n,1,a,b,j,0);
		}
		
		if( c == 1 ){
			
			for( int j=0;j<26;j++){
				if( num[j] != 0 ){
					upd(1,n,1,a,a+num[j]-1,j,1);
					a+=num[j];
				}	
			}
			
		}
		else{
			for( int j=25;j>=0;j--){
				if( num[j] != 0 ){
					upd(1,n,1,a,a+num[j]-1,j,1);
					a+=num[j];
				}
			}	
		}
	}
	
	for( int i=1;i<=n;i++){
		for( int j=0;j<26;j++){
			if(find(1,n,1,i,i,j) == 1)
				printf( "%c" ,char(j+'a'));
		}
	}	
	return 0;
}
