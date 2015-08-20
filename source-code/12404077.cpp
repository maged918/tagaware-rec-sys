//Language: GNU C++11


// There is nothing in a caterpillar that tells you its going to be a butterfly ----------------------

#include<bits/stdc++.h>
using namespace std;
#define INF 10000000000000000
#define f first
#define pii pair<pi,ll>
#define pi pair<ll,ll>
#define pb push_back

#define ll long long
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define fr freopen("input-3.txt","r",stdin)
#define fo freopen("output-3.txt","w",stdout)
#define mod 1000000007
vector<int>g[80],ge[80],eq[80];
bool vis[80][80]={0};
ll dp[80][80];
bool check_oppo(int i,int j,int cur){
	for(auto x:g[i+1]){
		if(x<=i or x>=j){

		}
		else{
			return 0;
		}
	}
	for(auto x:ge[i+1]){
		if(x<=i+1 or x>=j-1){

		}
		else{
			return 0;
		}
	}
	for(auto x:eq[i+1]){
		if(x==j-1 or x==i+1){

		}
		else{
			return 0;
		}
	}
	for(auto x:g[j-1]){
		if(x<=i or x>=j){

		}
		else{
			return 0;
		}
	}
	for(auto x:ge[j-1]){
		if(x<=i+1 or x>=j-1){

		}
		else{
			return 0;
		}
	}
	for(auto x:eq[j-1]){
		if(x==j-1 or x==i+1){

		}
		else{
			return 0;
		}
	}
	return 1;
}
bool check_left(int i,int j,int cur){
	for(auto x:g[i+1]){
		if(x<=i or x>=j){

		}
		else{
			return 0;
		}
	}
	for(auto x:ge[i+1]){
		if(x<=i+2 or x>=j){

		}
		else{
			return 0;
		}
	}
	for(auto x:eq[i+1]){
		if(x==i+1 or x==i+2){

		}
		else{
			return 0;
		}
	}
	for(auto x:g[i+2]){
		if(x<=i or x>=j){

		}
		else{
			return 0;
		}
	}
	for(auto x:ge[i+2]){
		if(x<=i+2 or x>=j){

		}
		else{
			return 0;
		}
	}
	for(auto x:eq[i+2]){
		if(x==i+1 or x==i+2){

		}
		else{
			return 0;
		}
	}
	return 1;
}
bool check_right(int i,int j,int cur){
	for(auto x:g[j-1]){
		if(x<=i or x>=j){

		}
		else{
			return 0;
		}
	}
	for(auto x:ge[j-1]){
		if(x<=i or x>=j-2){

		}
		else{
			return 0;
		}
	}
	for(auto x:eq[j-1]){
		if(x==j-1 or x==j-2){

		}
		else{
			return 0;
		}
	}
	for(auto x:g[j-2]){
		if(x<=i or x>=j){

		}
		else{
			return 0;
		}
	}
	for(auto x:ge[j-2]){
		if(x<=i or x>=j-2){

		}
		else{
			return 0;
		}
	}
	for(auto x:eq[j-2]){
		if(x==j-1 or x==j-2){

		}
		else{
			return 0;
		}
	}
	return 1;
}
int n;
ll rec(int i,int j){

	if(j-i-1==2){
		if(check_oppo(i,j,1)) return 1;
		return 0;
	}

	if(vis[i][j]) return dp[i][j];
	vis[i][j]=1;
	int cur=(i+2*n-j+1)/2;
	cur++;
	ll &ret=dp[i][j];
	ret=0;
	// case 1. two cur on opposite stacks
	if(check_oppo(i,j,cur)){
		ret+=rec(i+1,j-1);

	}
	if(check_left(i,j,cur)){
		ret+=rec(i+2,j);

	}
	if(check_right(i,j,cur)){
		ret+=rec(i,j-2);

	}
	return ret;
}
int main(){
	int k;
	cin >> n >> k;
	int x,y;
	string s;
	rep(i,k){
		cin >> x >> s >> y;
		if(s=="="){
			eq[x].pb(y);
			eq[y].pb(x);
		}
		else if(s==">="){
			ge[x].pb(y);
		}
		else if(s=="<="){
			ge[y].pb(x);
		}
		else if(s==">"){
			g[x].pb(y);
		}
		else if(s=="<"){
			g[y].pb(x);
		}
	}
	cout<<rec(0,2*n+1);
}
