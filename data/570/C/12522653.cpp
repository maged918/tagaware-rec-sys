//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;
int  n , m  ;
char str[300010] ;
struct node {
    int l,r ;
    int value ;
    int lpoint,rpoint ;
}a[300010<<2] ;
void Pushup(int k){
    //a[k].value=a[k<<1].value +a[k<<1|1].value ;
    a[k].lpoint = a[k<<1].lpoint ;
    a[k].rpoint = a[k<<1|1].rpoint;
    a[k].value =a[k<<1].value + a[k<<1|1].value;
    //cout<<a[k].value<<endl;
    if(a[k<<1].rpoint == 1 && a[k<<1|1].lpoint == 1){
        a[k].value++;
    }
}
void Build(int l,int r,int k)
{
    a[k].l = l,a[k].r = r,a[k].value = 0,a[k].lpoint = a[k].rpoint = 0;
    if(l == r ){
        if(str[l] == '.'){
            a[k].lpoint = a[k].rpoint  =1;
        }
        return ;
    }
    int mid = (l+r)>>1 ;
    Build(l,mid,k<<1) ;
    Build(mid+1,r,k<<1|1) ;
    Pushup(k) ;
}

void Insert(int pos,char *s,int k)
{
    //cout<<s[0]<<" "<<a[k].l<<" "<<a[k].r<<endl;
    if(a[k].l== a[k].r && a[k].l ==pos){
        a[k].value =  0;
        if(s[0] == '.'){
            a[k].lpoint =a[k].rpoint = 1;
        }
        else{
            a[k].lpoint =a[k].rpoint = 0;
        }
        return ;
    }
    int mid = (a[k].l+a[k].r)>>1;
    if(mid>=pos){
        Insert(pos,s,k<<1) ;
    }
    else if(mid< pos){
        Insert(pos,s,k<<1|1) ;
    }
    Pushup(k);
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        scanf("%s",str+1) ;
        Build(1,n,1) ;
        /*for(int i=1;i<n;i++){
            cout<<a[i].lpoint<<" "<<a[i].rpoint<<" "<<a[i].value<<endl;
        }*/
        for(int i=0;i<m;i++){
            char c[10];
            int pos ;
            scanf("%d%s",&pos,c) ;
            //printf("%c\n",c[0]) ;
            //printf("%c",c[0]) ;
            //printf(" %c\n",str[pos]);
            if(c[0] != '.' && str[pos]!='.' || c[0]=='.'&& str[pos]=='.'){
                printf("%d\n",a[1].value) ;
            }
            else{
                str[pos] = c[0] ;
                Insert(pos,c,1) ;
                printf("%d\n",a[1].value) ;
            }
        }
    }
    return 0;
}
