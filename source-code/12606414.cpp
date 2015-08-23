//Language: GNU C++11


#include <bits/stdc++.h>
#include <map>

inline int get_signed_int(){
	char c=getchar();int ret=0,neg=0;
	while(c!='-'&&!isdigit(c))c=getchar();
	if(c=='-')neg=1,c=getchar();
	do {ret = (ret<<3)+(ret<<1)+c-'0';
	}while(isdigit(c=getchar()));
	return neg?-ret:ret;
}


int main(){
    int n = get_signed_int(), k = get_signed_int();
    std :: unordered_map<int, long long> son, per;
    long long ret = 0;

    for(int i = 0; i < n; ++ i) {
        int tmp = get_signed_int();
        if(!(tmp % k)) {
            std :: unordered_map<int, long long> :: iterator it = per.find(tmp / k);
            std :: unordered_map<int, long long> :: iterator itSon = son.find(tmp / k);
            if(it != per.end()) {
                ret += it -> second;
                if(itSon != son.end()) {
                    std :: unordered_map<int, long long> :: iterator itPerTmp = per.find(tmp);
                    if(itPerTmp != per.end()){
                        itPerTmp -> second += itSon -> second;
                    }else {
                        per.insert(std :: make_pair(tmp, itSon -> second));
                    }
                }
            }else{
                if(itSon != son.end()) {
                    std :: unordered_map<int, long long> :: iterator itPerTmp = per.find(tmp);
                    if(itPerTmp != per.end()){
                        itPerTmp -> second += itSon -> second;
                    }else {
                        per.insert(std :: make_pair(tmp, itSon -> second));
                    }
                }
            }
        }

        std :: unordered_map<int, long long> :: iterator itSonTmp = son.find(tmp);
        if(itSonTmp != son.end()) ++ itSonTmp -> second;
        else son.insert(std :: make_pair(tmp, 1));
    }

    printf("%lld\n", ret);
    return 0;
}
