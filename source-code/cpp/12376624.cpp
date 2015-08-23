//Language: GNU C++


#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>


using namespace std;

bool flag[1000010];



int main(){
	int n;
	int capacity = 0;
	int cur = 0;
	char s;
	int num;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s == '+'){
			cur++;
			cin >> num;
			flag[num] = true;
		}
		if(s == '-'){
			cin >> num;
			if(!flag[num]){
				capacity++;
			}
			else{
				flag[num] = false;
				cur--;
			}
		}
		capacity = max(capacity,cur);
	}
	cout << capacity << endl;
}
