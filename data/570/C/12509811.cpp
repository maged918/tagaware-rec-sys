//Language: GNU C++11


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>

#ifdef DK
const int MAX = 100;
#else
const int MAX = 3e5 + 11;
#endif

using namespace std;

int N, M;
char A[MAX];

int main() {
#ifdef DK
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
  scanf("%d %d", &N, &M);
  scanf("%s", A);
  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] != '.') continue;
    int j = i;
    while (j < N && A[i] == A[j]) {
      j++;
    }
    res += j - i - 1;
    i = j - 1;
  }
  for (int i = 0; i < M; ++i) {
    int idx = 0;
    char ch = 0;
    scanf("%d %c\n", &idx, &ch);
    idx--;
    if (isalpha(A[idx]) && isalpha(ch)) {
      printf("%d\n", res);
      continue;
    }
    if (A[idx] == ch) {
      printf("%d\n", res);
      continue;
    }
    if (ch == '.') {
      if (idx > 0 && idx < N - 1 && A[idx - 1] == '.' && A[idx + 1] == '.') {
        res += 2;
      } else if (idx > 0 && A[idx - 1] == '.') {
        res++;
      } else if (idx < N - 1 && A[idx + 1] == '.') {
        res++;
      }
    } else {
      if (idx > 0 && idx < N - 1 && A[idx - 1] == '.' && A[idx + 1] == '.') {
        res -= 2;
      } else if (idx > 0 && A[idx - 1] == '.') {
        res--;
      } else if (idx < N - 1 && A[idx + 1] == '.') {
        res--;
      }
    }
    printf("%d\n", res);
    A[idx] = ch;
  }
  return 0;
}