//Language: GNU C++


#include<stdio.h>
#include<vector>
#include<algorithm>
#define V 100001
using namespace std;
typedef long long LL;
int H;
LL min(LL p,LL q){
	return (p<q)?p:q;
}
LL max(LL p,LL q){
	return (p>q)?p:q;
}
struct Block{
	int h;
	LL lf;
	LL rt;
	Block(){}
	Block(LL _lf,LL _rt):lf(_lf),rt(_rt){}
	void set(int _h,LL _lf,LL _rt){
		h = _h;
		lf = _lf;
		rt = _rt;
	}
	void normalize(){
		int t = H - h;
		while(t--){
			lf <<= 1LL;
			rt = (rt<<1LL) | 1LL;
		}
	}
	bool empty(){
		return lf>rt;
	}
	void intersect(Block& other){
		lf = max(lf,other.lf);
		rt = min(rt,other.rt);
	}
	bool emptyAfterIntersect(Block& other){
		return other.lf>rt || other.rt<lf;
	}
	void list(){
		printf("(%lld,%lld)\n",lf,rt);
	}
	bool operator < (const Block& rhs)const{
		if(lf==rhs.lf)
			return rt<rhs.rt;
		return lf<rhs.lf;
	}
};

Block yes[V], no[V];
vector<Block> result;
int topY=0, topN=0;

int main(){
	int i,q;
	int h,ans;
	LL L,R;
	Block now,tmp;
	Block ret;
	scanf("%d%d",&H,&q);
	for(i=0;i<q;i++){
		scanf("%d%lld%lld%d",&h,&L,&R,&ans);
		if(ans)
			yes[topY++].set(h,L,R);
		else
			no[topN++].set(h,L,R);
	}
	for(i=0;i<topY;i++)
		yes[i].normalize();
	for(i=0;i<topN;i++)
		no[i].normalize();
	ret.set(1,1LL,1LL);
	ret.normalize();
	for(i=0;i<topY&&!ret.empty();i++)
		ret.intersect(yes[i]);
	if(ret.empty())
		printf("Game cheated!\n");
	else{
		sort(no,no+topN);
		for(i=0;i<topN;i++){
			if(!ret.emptyAfterIntersect(no[i])){
				if(no[i].lf>ret.lf)
					result.push_back( Block(ret.lf, no[i].lf-1) );
				ret.lf = no[i].rt + 1;
			}
		}
		if(!ret.empty())
			result.push_back(ret);
		if(result.size()==0)
			printf("Game cheated!\n");
		else if(result.size()!=1)
			printf("Data not sufficient!\n");
		else if(result[0].lf!=result[0].rt)
			printf("Data not sufficient!\n");
		else
			printf("%lld\n",result[0].lf);
	}
	return 0;
}

 	 	 					 	 			 			       	 		