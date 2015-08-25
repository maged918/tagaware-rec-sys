//Language: GNU C++


#include <iostream>
using namespace std;
bool canfit(int a,int b,int x,int y){
	if(x<=a&&y<=b)
		return 1;
	return 0;
}
int main() {
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	int x4,y4;
	if(canfit(x1,y1,x2,y2)){
		x4=x1-x2;y4=y1-y2;
		//cout<<x4<<" "<<y4<<endl;
		if(canfit(x4,y1,x3,y3)){
			cout<<"YES";return 0;
		}
		if(canfit(x1,y4,x3,y3)){
			cout<<"YES";return 0;
		}
		if(canfit(x4,y1,y3,x3)){
			cout<<"YES";return 0;
		}
		if(canfit(x1,y4,y3,x3)){
			cout<<"YES";return 0;
		}
	}
	if(canfit(x1,y1,y2,x2)){
		x4=x1-y2;y4=y1-x2;
		//cout<<x4<<" "<<y4<<endl;
		if(canfit(x4,y1,x3,y3)){
			cout<<"YES";return 0;
		}
		if(canfit(x1,y4,x3,y3)){
			cout<<"YES";return 0;
		}
		if(canfit(x4,y1,y3,x3)){
			cout<<"YES";return 0;
		}
		if(canfit(x1,y4,y3,x3)){
			cout<<"YES";return 0;
		}
	}
	cout<<"NO";
		
	return 0;
}