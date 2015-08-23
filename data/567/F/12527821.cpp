//Language: GNU C++11


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
using namespace std;
class sp{
  public:
  int q,e;
  sp *w;
  sp(int q1,sp *w1,int e1){
   q=q1;w=w1;e=e1;}
};
char g[3];
long long a[70][70];
sp *a1[70];
bool l(int q,int c,int v){
  if((q<c)||(v<q))
   return 1;
  return 0;
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int q,w,e,r,t,v;
  cin>>q>>t;
  for(w=0;w<q;w++)
   a1[w]=0;
  for(w=0;w<t;w++){
   cin>>e>>g>>r;
   e--;r--;
   if(e==r){
    if((g[0]!='=')&&(g[1]!='=')){
     cout<<0;
     return 0;}
    continue;}
   if(g[0]=='='){
    a1[e]=new sp(r,a1[e],0);
    a1[r]=new sp(e,a1[r],0);}
   if(g[0]=='>'){
    v=e;e=r;r=v;
    g[0]='<';}
   if(g[0]=='<')
    if(g[1]=='=')
     a1[e]=new sp(r,a1[e],2);
    else
     a1[e]=new sp(r,a1[e],1);}
  q*=2;
  for(w=0;w<q;w++)
   for(e=0;e<q;e++)
    a[w][e]=0;
  bool b1,b2,b3;
  sp *c;
  for(w=0;w<q-1;w++){
   b1=1;
   for(c=a1[w];c;c=c->w)
    if(((c->e==1)&&(c->q==w+1))||(c->q!=w+1)){
     b1=0;
     break;}
   for(c=a1[w+1];c;c=c->w)
    if(((c->e==1)&&(c->q==w))||(c->q!=w)){
     b1=0;
     break;}
   if(b1)
    a[w][w+1]=1;}
  for(w=2;w<q;w+=2)
   for(e=0;e+w<=q;e++){
    b1=b2=b3=1;
    if(e-1<0)
     b1=b2=0;
    else
     for(c=a1[e-1];c;c=c->w){
      if(c->q==e-2){
       if(c->e==0)
        b2=0;
       if(c->e==1)
        b1=b2=0;
       if(c->e==2)
        b2=0;
       continue;}
      if(c->q==e+w){
       if(c->e==0)
        b1=b3=0;
       if(c->e==1)
        b1=b2=0;
       if(c->e==2)
        b1=0;
       continue;}
      if(l(c->q,e-2,w+e))
       b1=b2=0;}
    if(e-2<0)
     b1=0;
    else
     for(c=a1[e-2];c;c=c->w){
      if(c->q==e-1){
       if(c->e==1)
        b1=0;
       continue;}
      if(l(c->q,e-2,w+e-1))
       b1=0;}
    if(e+w>=q)
     b2=b3=0;
    else
     for(c=a1[e+w];c;c=c->w){
      if(c->q==e+w+1){
       if(c->e==0)
        b2=0;
       if(c->e==1)
        b2=b3=0;
       if(c->e==2)
        b2=0;
       continue;}
      if(c->q==e-1){
       if(c->e==0)
        b1=b3=0;
       if(c->e==1)
        b2=b3=0;
       if(c->e==2)
        b3=0;
       continue;}
      if(l(c->q,e-1,w+e+1))
       b2=b3=0;}
    if(e+w+1>=q)
     b3=0;
    else
     for(c=a1[e+w+1];c;c=c->w){
      if(c->q==e+w){
       if(c->e==1)
        b3=0;
       continue;}
      if(l(c->q,e,w+e+1))
       b3=0;}
    if(b1)
     a[e-2][e+w-1]+=a[e][e+w-1];
    if(b2)
     a[e-1][e+w]+=a[e][e+w-1];
    if(b3)
     a[e][e+w+1]+=a[e][e+w-1];}
  cout<<a[0][q-1];
  return 0;}
