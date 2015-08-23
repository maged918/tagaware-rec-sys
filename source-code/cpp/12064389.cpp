//Language: GNU C++11


#include <cstdio>
#include <algorithm>
#include <cstdlib>

 using namespace std;

int a;
pair< int ,pair<int,int > > x[1000005];
 int main()
 {
  int n ;
  int i , j , max = 0;
  scanf("%d",&n);
  for(i = 1; i <= n; i++) { scanf("%d",&a);
                          if(x[a].first == 0) x[a].second.first = i;
                          x[a].second.second = i;
                          x[a].first ++;
                          if(x[a].first > max) max = x[a].first;
                         }
int min = 1000000 , t , k;
 for(i = 1; i <= 1000000 ; i++){
     if(x[i].first == max && x[i].second.second - x[i].second.first < min) {
             min = x[i].second.second - x[i].second.first;
             t = x[i].second.first;
             k = x[i].second.second;
            }
   }
 printf("%d %d",t, k);
 }