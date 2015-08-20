//Language: GNU C++


#include<stdio.h>
int n;
int count=0;
int min=0;
int max=0;
void swap(int *a,int *b){
	int temp;
	temp=*a;;
	*a=*b;
	*b=temp;
}
int main(){
	scanf("%d",&n);
	int a[n];
	int b[n];
	for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<n;i++){
		if(a[i]>0) min+=1;
}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++) {
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
				swap(&b[i],&b[j]);
		}
	}
}
	if(min>n-min){
		for(int i=0;i<2*(n-min)+1;i++) max+=b[i];
}
	if(min==n-min){
		for(int i=0;i<2*(n-min);i++) max+=b[i];
}
	if(min<n-min){
		for(int i=n-1;i>=n-2*min-1;i--) max+=b[i];
}
printf("%d",max);
}
