//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int art[6] ;
bool check(int x1 , int x2, int y1 , int y2){
	if((x1-y1>-1&&x2-y2>-1)||(x1-y2>-1&&x2-y1>-1)) return true ;
   return false ;	
}
string Gerald(){
	
	if((art[0]<art[2]&&art[1]<art[2])||(art[0]<art[3]&&art[1]<art[3])) return "NO" ;
	if((art[0]<art[2]&&art[0]<art[3])||(art[1]<art[2]&&art[1]<art[3])) return "NO" ;
	 int r1 = art[0]-art[2] , r2=art[0]-art[3];
	 int c1 = art[1]-art[2] , c2 = art[1]-art[3] ;
	 if(check(r1,art[1],art[4],art[5])||check(r2,art[1],art[4],art[5])||check(art[0],c1,art[4],art[5])||check(art[0],c2,art[4],art[5])) return "YES" ;
	 return "NO";
	  
	
	}
int main(){
	for(int i=0;i<6;i++)cin>>art[i] ;
	cout<<Gerald()<<endl;
	
	
	
return 0;
}
