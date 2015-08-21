//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >>n;
	set<int> S;
//	int a[n];
//	bool b[n];
	int current_ans=0,max_ans=0,initial=0;
	while(n--){
		char c;
		int reg_id;
		cin >> c >> reg_id;
		if(c==*"-"){
			if(S.count(reg_id)){
				S.erase(reg_id);
				current_ans-=1;
			}
			else{
				max_ans++;;
			}
		}
		else{
			S.insert(reg_id);
			current_ans+=1;
		}
		
		if(abs(current_ans)>max_ans)
			max_ans=abs(current_ans);
	}
	cout<<max_ans<<endl;
	return 0;
}
