//Language: GNU C++11


#include<stdio.h>
#include<set>

using namespace std;

int main()
{
 int visitors = 0, fromstart = 0;
 int n;
 scanf("%d ", &n);
 char io, ws;
 int x;
 int in[110];
 set<int> inl;
 for (int i = 0; i < n; i++){
   scanf("%c%c%d ", &io, &ws, &x);
   if (io == '+') {
     inl.insert(x); 
     in[i] = inl.size();
   }
   else 
   if (io == '-'){
     if (inl.count(x)!=0) {
       inl.erase(x);
       in[i] = inl.size();
     }
     else
     {
       in[i] = 1;
       for (int j = 0; j < i; j++){
	 in[j]++;
	 if (in[j]>visitors) visitors = in[j];
       } 
     }
   }
   if (in[i]>visitors) visitors = in[i];
   //printf("%d %d %c %d\n", i, in[i], io, x);
 }
 printf("%d\n", visitors);
 return 0;
}

