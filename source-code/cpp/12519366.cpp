//Language: GNU C++


#include <iostream>
using namespace std;
int h(int n){
	if(n==2){
		return 1;
	}
	if(n<2){
		return 0;
	}
	else return h(n-1)+1;
}

int main(){
	int n,m;
	cin >> n >>m;
	string s;
	cin>>s;
	int initcount=0;
	int currmax=0;
	for(int i=0;i<n-1;i++){
			if(s[i]!='.'){
				initcount+=h(currmax);
				//cout << i << " " << currmax << " " << h(currmax) << endl;
				currmax = 0;
				continue;
			}
			else{
				if(s[i+1]=='.'){
					if(currmax==0){
						currmax=2;
					}
					else{
						currmax++;
					}
					//cout << i << " "<< currmax<< endl;
				}
			}
		}
	initcount += h(currmax);
	//cout << initcount << endl;
	for(int it=0;it<m;it++){
		int x;
		char y;
		cin>>x;
		cin>>y;
		if(n>1){
			if(x==1){
				if(s[1]=='.'){
					if(y=='.'){
						if(s[0]!='.'){
							initcount+=1;
						}
						cout << initcount << endl;
					}
					else{
						if(s[0]=='.'){
							initcount-=1;
						}
						cout << initcount << endl;
					}
				}
				else{
					cout <<initcount<<endl;
				}
			}
			else if(x<s.length()){
				if(s[x-2]=='.' && s[x]=='.'){
					//ut << "step1" << endl;
					if(y=='.'){
						if(s[x-1]!='.'){
							initcount+=2;
						}
						cout << initcount << endl;
					}
					else{
						if(s[x-1]=='.'){
							initcount-=2;
						}
						cout << initcount << endl;
					}
				}
				else if(s[x-2]=='.' ||  s[x]=='.'){
					if(y=='.'){
						if(s[x-1]!='.'){
							initcount+=1;
						}
						cout << initcount << endl;
					}
					else{
						if(s[x-1]=='.'){
							initcount-=1;
						}
						cout << initcount << endl;
					}
				}
				else{
					cout << initcount << endl;
				}
			}
			if(x==s.length()){
				if(s[s.length()-2]=='.'){
					if(y=='.'){
						if(s[s.length()-1]!='.'){
							initcount+=1;
						}
						cout << initcount << endl;
					}
					else{
						if(s[s.length()-1]=='.'){
							initcount-=1;
						}
						cout << initcount << endl;
					}
				}
				else{
					cout << initcount << endl;
				}
			}
		}
		if(n==1){
			cout << 0 << endl;
		}
		
		s[x-1]=y;
		//cout << s << endl; 

		// int currmax=0;
		// for(int i=0;i<n-1;i++){
		// 	if(s[i]!='.'){
		// 		count+=h(currmax);
		// 		//cout << i << " " << currmax << " " << h(currmax) << endl;
		// 		currmax = 0;
		// 		continue;
		// 	}
		// 	else{
		// 		if(s[i+1]=='.'){
		// 			if(currmax==0){
		// 				currmax=2;
		// 			}
		// 			else{
		// 				currmax++;
		// 			}
		// 			//cout << i << " "<< currmax<< endl;
		// 		}
		// 	}
		// }
		//cout << count +h(currmax)<< endl;
	}
	
}