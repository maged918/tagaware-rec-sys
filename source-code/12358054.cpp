//Language: GNU C++


#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

bool in[1001000] = {};
long lysh = 0, cur = 0;

int main()
{
    long n, temp;
    cin >> n;
    char c;
    for(long i = 0; i < n; i++){
      cin >> c >> temp;
  //    assert(c == '+' || c == '-');
      if(c == '+'){
        in[temp] = 1;
        cur++;
      }else if (c == '-'){
        if(in[temp]){
          cur--;
          in[temp] = 0;
        }else{
          lysh++;
        }
      }
      lysh = max(lysh, cur);
    }
    cout << lysh << endl;
    return 0;
}
