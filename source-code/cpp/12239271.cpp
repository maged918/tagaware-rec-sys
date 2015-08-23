//Language: GNU C++11


#include<cstdio>
#include<algorithm>
#include<iostream>
#define X first
#define Y second
#define mp make_pair
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
struct answer{
	int h,a;
	LL l,r;
}ans[N];
LL bigmax(LL x,LL y){
	return x < y ? y : x;
}
LL bigmin(LL x,LL y){
	return x < y ? x : y;
}
bool cmpans(answer x,answer y){
	return (x.h != y.h) ? x.h < y.h : x.a > y.a;
}
int cross(pair<LL,LL>x,pair<LL,LL>y){
	if (x.X > y.Y || x.Y < y.X) return 0;
	return 1;
}
void common(pair<LL,LL> &x,pair<LL,LL> y){
	x.X = bigmax(x.X,y.X);
	x.Y = bigmin(x.Y,y.Y);
}
int cover(pair<LL,LL> x,pair<LL,LL> y){
	return x.Y >= y.Y && x.X <= y.X;
}
void remove(pair<LL,LL> &x,pair<LL,LL> y){
	if (x.X >= y.X) x.X = y.Y + 1;
	else x.Y = y.X - 1;
}
pair<LL,LL>av[N],b[N],no[N];
LL walk(int n,int m){
	int cav = 0,cb = 0;
	sort(ans + 1,ans + 1 + m,cmpans);
	av[cav = 1] = mp(1,1);
	for (int h = 1,q = 1;h <= n;h ++){
		if (q > m || ans[q].h > h){
			if (h == n) break;
			for (int i = 1;i <= cav;i ++){
				av[i].X <<= 1,av[i].Y = av[i].Y * 2 + 1;
			}
			continue;
		}
		pair<LL,LL>A = mp(1LL << h - 1,(1LL << h) - 1);
		for (;q <= m && ans[q].h == h && ans[q].a == 1;q ++){
			if (!cross(A,mp(ans[q].l,ans[q].r))) return -1;
			common(A,mp(ans[q].l,ans[q].r));
		}
		cb = 0;
		for (int i = 1;i <= cav;i ++){
			if (!cross(A,av[i])) continue;
			b[++ cb] = A,common(b[cb],av[i]);
		}
		if (!cb) return -1;
		cav = cb;
		for (int i = 1;i <= cb;i ++) av[i] = b[i];
		int cno = 0;
		for (;q <= m && ans[q].h == h && ans[q].a == 0;q ++){
			no[++ cno] = mp(ans[q].l,ans[q].r);
		}
		if (!cno){
			if (h == n) break;
			for (int i = 1;i <= cav;i ++){
				av[i].X <<= 1;
				av[i].Y = av[i].Y * 2 + 1;
			}
			continue;
		}
		sort(no + 1,no + cno + 1);
		cb = 0;
		int r = 1;
		for (int i = 1,j;i <= cno;i = j){
			pair<LL,LL> cut = no[i];
			for (j = i + 1;j <= cno && no[j].X <= cut.Y;j ++){
				cut.Y = bigmax(cut.Y,no[j].Y);
			}
			for (;r <= cav && av[r].Y < cut.X;r ++){
				b[++ cb] = av[r];
			}
			for (;r <= cav && av[r].Y <= cut.Y;r ++){
				if (!cover(cut,av[r])){
					b[++ cb] = av[r],remove(b[cb],cut);
				}
			}
			if (r <= cav && cross(av[r],cut)){
				if (av[r].X < cut.X){
					b[++ cb] = mp(av[r].X,cut.X - 1);
					av[r].X = cut.X;
				}
				remove(av[r],cut);
			}
		}
		for (;r <= cav;r ++){
			b[++ cb] = av[r];
		}
		if (!cb) return -1;
		cav = cb;
		for (int i = 1;i <= cb;i ++) av[i] = b[i];
		if (h == n) break;
		for (int i = 1;i <= cav;i ++){
			av[i].X <<= 1;
			av[i].Y = av[i].Y * 2 + 1;
		}
	}
	if (cav > 1 || av[1].Y - av[1].X > 0) return 0;
	return av[1].X;
}
int main(){
	int h,q;
	cin >> h >> q;
	for (int i = 1;i <= q;i ++){
		cin >> ans[i].h >> ans[i].l >> ans[i].r >> ans[i].a;
	}
	LL ck = walk(h,q);
	if (ck == -1) cout << "Game cheated!" << endl;
	if (ck == 0) cout << "Data not sufficient!" << endl;
	if (ck > 0) cout << ck << endl;
	
	return 0;
}
