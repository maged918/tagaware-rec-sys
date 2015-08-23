//Language: MS C++


#include<stdio.h>
#include<stdlib.h>
#include <iostream> 
#include <queue>      
#include <vector>      
#include <functional>     

int n,i,j,k,pos,neg,tem1,tem2,end,compare,target,size,sum1,sum2;
int a[200][2];
int b[200][2];


int firstfounda(int b){
	int j;
	if (b==1){
		for (j=0;j<n;j++){
			if (a[j][0] > 0){
				return j;
			}
		}
	} else {
		for (j=0;j<n;j++){
			if (a[j][0] < 0){
				return j;
			}
		}
	}
	return 200;
}

int firstfoundb(int c){
	int j;
	if (c==1){
		for (j=0;j<n;j++){
			if (b[j][0] > 0){
				return j;
			}
		}
	} else {
		for (j=0;j<n;j++){
			if (b[j][0] < 0){
				return j;
			}
		}
	}
	return 200;
}

int main(){
	
	scanf("%d",&n);
	for (i=0; i<n; i++){
		scanf("%d %d", &tem1, &tem2);
		a[i][0]=tem1;
		a[i][1]=tem2;
		b[i][0]=tem1;
		b[i][1]=tem2;
	}
	
	end =0;
	compare = 1;
	sum1 = 0;
	sum2 = 0;
	while (end == 0){
		if (compare == 1){
			
			target = firstfounda(compare);
			for (i=0; i<n; i++){
				if (a[target][0] > a[i][0] && a[i][0]>0){
					target = i;
				} 
			}
			compare = 0;
		} else {
			
			target = firstfounda(compare);
			for (i=0; i<n; i++){
				if (a[target][0] < a[i][0] && a[i][0]<0){
					target = i;
				} 
			}
			compare = 1;
		}
		if (target == 200){
			end = 1;
			break;
		}
		sum1 = sum1 + a[target][1];
		a[target][0] = 0;
		a[target][1] = 0;
		
	}
	
	end =0;
	compare = 0;

	while (end == 0){
		if (compare == 1){
			target = firstfoundb(compare);
			for (i=0; i<n; i++){
				if (b[target][0] > b[i][0] && b[i][0]>0){
					target = i;
				} 
			}
			compare = 0;
		} else {
			target = firstfoundb(compare);
			for (i=0; i<n; i++){
				if (b[target][0] < b[i][0] && b[i][0]<0){
					target = i;
				} 
			}
			compare = 1;
		}
		if (target == 200){
			end = 1;
			break;
		}
		sum2 = sum2 + b[target][1];
		b[target][0] = 0;
		b[target][1] = 0;
	}	
	
	if (sum1>sum2){
		printf("%d\n", sum1);
	} else{
		printf("%d\n", sum2);
	}
	 
	return 0;
}
