//Language: GNU C++11


# include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
char a[300005];
set<int> s;

int get(int x, int y){
  if(y > x) swap(x,y);
  return max(x-y-2,0);
}

int main(){ 
  cin >> n >> m;
  scanf("%s",a+1);
  
  for(int i = 1; i <= n; i++) if(a[i] != '.') s.insert(i);
  s.insert(0);  s.insert(n+1);

  int tot = 0;
  int last = 0;
  for(int x : s){
    tot += get(x, last);
    last = x;
  }

  for(int i = 0; i < m; i++){
    int x; char c;
    cin >> x >> c;
    if((a[x]=='.' and c=='.') or (a[x]!='.' and c!='.')){}
    else if(c=='.' and a[x]!='.'){
        auto next = s.upper_bound(x);
        auto prev = s.lower_bound(x); --prev;
        tot -= get(x,*prev);
        tot -= get(x,*next);
        tot += get(*prev,*next);
        s.erase(x);
    }
    else{
        auto next = s.upper_bound(x);
        auto prev = s.lower_bound(x); --prev;
        tot += get(x,*prev);
        tot += get(x,*next);
        tot -= get(*prev,*next);
        s.insert(x);
    }
    a[x] = c;
    printf("%d\n", tot);
  }
  return 0;
}