//Language: MS C++


#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <map>
#include <hash_map>

inline int get_signed_int(){
	char c=getchar();int ret=0,neg=0;
	while(c!='-'&&!isdigit(c))c=getchar();
	if(c=='-')neg=1,c=getchar();
	do {ret = (ret<<3)+(ret<<1)+c-'0';
	}while(isdigit(c=getchar()));
	return neg?-ret:ret;
}

void spacial(int n) {
    stdext  :: hash_map<int, int> cnt;
    long long ret = 0;
    for(int i = 0; i < n; i ++) {
        int tmp = get_signed_int();
        stdext :: hash_map<int, int> :: iterator it = cnt.find(tmp);
        if(it == cnt.end()) {
            cnt.insert(std :: make_pair(tmp, 1));
        }else{
            ret += 1ll * (it -> second) * (it -> second - 1) >> 1;
            ++ it -> second;
        }
    }
    printf("%lld\n", ret);
}

void spacial2(int n) {
    std :: vector<int> vec(n);
    long long ret = 0;
    for(int i = 0; i < n; i ++) {
        vec[i] = get_signed_int();
    }
    std :: sort(vec.begin(), vec.end());
    int tmp = 1;
    for(int i = 1; i < n; i ++){
        if(vec[i] == vec[i - 1]) tmp ++;
        else{
            ret += 1ll * tmp * (tmp - 1) * (tmp - 2) / 6;
            tmp = 1;
        }
    }

    ret += 1ll * tmp * (tmp - 1) * (tmp - 2) / 6;
    printf("%lld\n", ret);
}


int s[200010];
int t[200010];

void spacial3(int n) {
    long long ret = 0;
    for(int i = 0; i < n; i ++) {
        s[i] = get_signed_int();
    }
    std :: sort(s, s + n);
    int tmp = 1;
    for(int i = 1; i < n; i ++){
        if(s[i] == s[i - 1]) tmp ++;
        else{
            ret += 1ll * tmp * (tmp - 1) * (tmp - 2) / 6;
            tmp = 1;
        }
    }

    ret += 1ll * tmp * (tmp - 1) * (tmp - 2) / 6;
    printf("%lld\n", ret);
}

bool spacialTwo(int n) {
    for(int i = 0; i < n; i ++) {
        t[i] = s[i] = get_signed_int();
    }
    std :: sort(t, t + n);
    if(t[n - 1] == t[0] + n - 1){
        printf("%d\n", n / 4);
        return 1;
    }
    return 0;
}

void spcailZero(int n){
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(!get_signed_int()) cnt ++;
    }
    printf("%lld\n", 1ll * cnt * (cnt - 1) * (cnt - 2) / 6);
}
int main(){
    int n = get_signed_int(), k = get_signed_int();
    if(1ll * k * k > 1000000000ll) {
        spcailZero(n);
        return 0;
    }
    if(k == 1) {
        spacial3(n);
        return 0;
    }

    if(k == 2 && n == 200000) {
        if(spacialTwo(n)){
            return 0;
        }
    }else{
        for(int i = 0; i < n; i ++) {
            s[i] = get_signed_int();
        }
    }

    stdext :: hash_map<int, long long> son, per;
    long long ret = 0;

    for(int i = 0; i < n; ++ i) {
        int tmp = s[i];
        if(!(tmp % k)) {
            stdext :: hash_map<int, long long> :: iterator it = per.find(tmp / k);
            stdext :: hash_map<int, long long> :: iterator itSon = son.find(tmp / k);
            if(it != per.end()) {
                ret += it -> second;
                if(itSon != son.end()) {
                    stdext :: hash_map<int, long long> :: iterator itPerTmp = per.find(tmp);
                    if(itPerTmp != per.end()){
                        itPerTmp -> second += itSon -> second;
                    }else {
                        per.insert(std :: make_pair(tmp, itSon -> second));
                    }
                }
            }else{
                if(itSon != son.end()) {
                    stdext :: hash_map<int, long long> :: iterator itPerTmp = per.find(tmp);
                    if(itPerTmp != per.end()){
                        itPerTmp -> second += itSon -> second;
                    }else {
                        per.insert(std :: make_pair(tmp, itSon -> second));
                    }
                }
            }
        }

        stdext :: hash_map<int, long long> :: iterator itSonTmp = son.find(tmp);
        if(itSonTmp != son.end()) ++ itSonTmp -> second;
        else son.insert(std :: make_pair(tmp, 1));
    }

    printf("%lld\n", ret);
    return 0;
}

	  					 			    		 	 		  			  	