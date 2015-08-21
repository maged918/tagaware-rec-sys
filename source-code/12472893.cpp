//Language: GNU C++11


#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int>v[100010];
pair<int,int>dist[100010];
pair<int,int>ans[100010];
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>v[i].first,v[i].second=i;
	sort(v,v+n);
	dist[0].first=abs(v[0].first-v[1].first);
	dist[0].second=abs(v[0].first-v[n-1].first);
	dist[n-1].first=abs(v[n-1].first-v[n-2].first);
	dist[n-1].second=abs(v[n-1].first-v[0].first);
	for(int i=1;i<n-1;i++){
		dist[i].first=abs(v[i-1].first-v[i].first);
		dist[i].first=min(dist[i].first,abs(v[i+1].first-v[i].first));
		dist[i].second=abs(v[i].first-v[0].first);
		dist[i].second=max(dist[i].second,abs(v[i].first-v[n-1].first));
	}
	for(int i=0;i<n;i++){
		ans[v[i].second].first=dist[i].first;
		ans[v[i].second].second=dist[i].second;
	}
	for(int i=0;i<n;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}
