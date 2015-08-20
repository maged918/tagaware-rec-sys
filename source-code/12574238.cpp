//Language: GNU C++


#include <cstdio>

int main() {
  int m, n;
  scanf("%d %d", &n, &m);
  char s[300002];
  bool flag = 0;
  int answer = 0;
  s[0] = 'a';
  getchar();
  for(int i = 1; i < n+1; i++) {
    scanf("%c", s+i);
    if (s[i] == '.') {
      if (flag == 1) {
        answer ++;
      }
      flag = 1;
    }
    else {
      flag = 0;
    }
  }
  s[n+1] = 'a';
  for(int i = 0; i < m; i++) {
    int x;
    char c;
    scanf("%d %c", &x, &c);
    if(c == '.' && s[x] != '.') {
      answer += (s[x-1] == '.');
      answer += (s[x+1] == '.');
    }
    if(c != '.' && s[x] == '.') {
      answer -= (s[x-1] == '.');
      answer -= (s[x+1] == '.');
    }
    s[x] = c;
    printf("%d\n", answer);
  }
  return 0;
}
