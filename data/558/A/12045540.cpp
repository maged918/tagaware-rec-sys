//Language: GNU C++11


#include <cstdio>
int min(int x,int y){
  if(x>y){
    return(y);
  }
  else{
    return(x);
  }
}
int p[100010];
int n[100010];
int main(){
  int a,b,c,d,e,f,g,r=0;
  scanf("%d",&a);
  for(b=0,c=0,d=0;b<a;b++){
    scanf("%d",&e);
    scanf("%d",&f);
    if(e>0){
      p[e]=f;
      c++;
    }
    if(e<0){
      e=-e;
      n[e]=f;
      d++;
    }
    g=min(c,d);
  }
  for(b=0,e=0;e<min(g+1,c);b++){
    if(p[b]>0){
      r+=p[b];
      e++;
    }
  }
  for(b=0,e=0;e<min(g+1,d);b++){
    if(n[b]>0){
      r+=n[b];
      e++;
    }
  }
  printf("%d\n",r);
}

