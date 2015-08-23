//Language: GNU C++


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll city[105],citywon[105];

int main(){

	ll n,m,index,max_votes,i;
	cin>>n>>m;
    
    while(m--){

    	max_votes=0;
        index=0;
    	for(i=0;i<n;i++){
    		cin>>city[i];

    		if(max_votes<city[i]){
    			max_votes=city[i];
    			index=i;
    		}
    	}

    	citywon[index]++;
    }

    max_votes=citywon[0];
    index=1;
    for(i=1;i<n;i++){
       
       if(max_votes<citywon[i]){
       	max_votes=citywon[i];
       	index=i+1;
       }
    }

    cout<<index<<endl;

	return 0;
}