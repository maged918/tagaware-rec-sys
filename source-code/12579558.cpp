//Language: GNU C++


#include <iostream>

using namespace std;

int main(){
	long int election[101][101], vote, candidate_cities[101] = {0}, m, n, max, candidate_max;
	
	cin >> n >> m;
	for(int i = 0; i< m; i++){
		candidate_max = 0;
		cin >> max;
		for(int j = 1; j< n; j++){
			cin >> vote;
			if(vote > max){
				candidate_max = j;
				max = vote;
			}
		}
		candidate_cities[candidate_max]++;
	}
	
	
	candidate_max = 0;
	for(int i = 1; i< n; i++){
		if(candidate_cities[i] > candidate_cities[candidate_max]){
			candidate_max = i;
		}
	}
	
	cout << candidate_max +1 << endl;
	
	return 0;
}
