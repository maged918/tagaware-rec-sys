//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long LL;
typedef set<pair<LL,LL>>::iterator PP;

set<pair<LL,LL>> segSet,tmpSet;
map<LL,LL> flag;
bool GameCheated = false;

PP segFind(pair<LL,LL> val){
	auto rit = segSet.lower_bound(val);
	auto lit = segSet.end();
	auto tmp = lit;
	if(rit != segSet.begin()){
		tmp = rit;
		lit = --tmp;
	}
	for(int i = 0;i < 2;++i){
		tmp = (i ? lit : rit);
		if(tmp != segSet.end()){
			if(tmp->first <= val.first && tmp->second >= val.second) return tmp;
		}
	}
	return segSet.end();
}
void fun(PP p,pair<LL,LL> x){
	//存在有线段[l,r]半酣线段[x.first,x.second]
	LL be[2],ed[2];
	be[0] = p->first,ed[0] = x.first - 1;
	be[1] = x.second + 1,ed[1] = p->second;
	segSet.erase(p);
	segSet.insert(x);
	for(int i = 0;i < 2;++i)
		if(be[i] <= ed[i]) segSet.insert(make_pair(be[i],ed[i]));
}
void solve(LL x,LL y){
	tmpSet.clear();
	auto lit = segSet.lower_bound(make_pair(x,x));
	auto rit = segSet.upper_bound(make_pair(y,y));
	for(;lit != rit;++lit){
		if((lit->first == x || lit->first == y) && flag.find(lit->first) == flag.end()){
			continue;
		}
		tmpSet.insert(*lit);
	}
	if(tmpSet.size() == 0) GameCheated = true;
	swap(tmpSet,segSet);
}
void remove(LL x,LL y){
	auto lit = segSet.lower_bound(make_pair(x,x));
	auto rit = segSet.upper_bound(make_pair(y,y));
	while(lit != rit){
		/* 注意这里的删除和平时的数组删除是不一样的 */
		lit = segSet.erase(lit);
	}
}
int main(){
	int	h,q;
	cin >> h >> q;
	segSet.insert(make_pair(1LL << (h - 1),(1LL << h) - 1));
	LL x,L,R,ans;
	LL tl,tr;
	for(int i = 0;i < q;++i){
		cin >> x >> L >> R >> ans;
		if(GameCheated) continue;
		tl = L << (h - x);
		tr = tl + ((R - L + 1) << (h - x)) - 1;
		//将线段[x,y]分成[x,x],[y,y]，然后插入到集合中，方便后面的操作
		auto lit = segFind(make_pair(tl,tl));

		flag.clear();
		if(tl != tr){
			if(lit != segSet.end()) flag[tl] = 1;
			if(lit != segSet.end()) fun(lit,make_pair(tl,tl));		//存在有线段[l,r]半酣线段[tl,tl]
			else segSet.insert(make_pair(tl,tl));					//不存在线段[l,r]包含线段[tl,tl]

			auto rit = segFind(make_pair(tr,tr));					//注意为什么要放在这里，因为上面lit的操作会影响rit的操作

			if(rit != segSet.end()) flag[tr] = 1;
			if(rit != segSet.end()) fun(rit,make_pair(tr,tr));		//存在有线段[l,r]半酣线段[tr,tr]
			else segSet.insert(make_pair(tr,tr));					//不存在线段[l,r]包含线段[tr,tr]
		}else{
			if(lit != segSet.end()) flag[tl] = 1;
			if(lit != segSet.end()) fun(lit,make_pair(tl,tl));
			else segSet.insert(make_pair(tl,tl));
		}
		if(ans){
			//[tl,tr]中存在出口
			solve(tl,tr);
		}else{
			//[tl,tr]中不存在出口
			remove(tl,tr);
		}
	}
	if(GameCheated || segSet.size() == 0){
		cout << "Game cheated!" << endl;
	}else if(segSet.size() == 1){
		if(segSet.begin()->first == segSet.begin()->second)
			cout << segSet.begin()->first << endl;
		else cout << "Data not sufficient!" << endl;
	}else cout << "Data not sufficient!" << endl;
	return 0;
}
