//Language: GNU C++


#include<bits/stdc++.h>
#define sz 211111
#define ll long long
using namespace std;
int n, k,idx;
ll a[sz],num[sz];

map<ll,int>chk;

ll bit[3][sz]={0};

void update(int lvl,int pos,ll val){
    while(pos<sz){
        bit[lvl][pos]+=val;
        pos+=(pos&-pos);

    }
}

ll query(int lvl, int pos){
    ll sum=0;
    while(pos>0){
        sum+=bit[lvl][pos];
        pos-=(pos&-pos);

    }
    return sum;
}


int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    cin>>n>>k;
    idx=0;
    for(int i = 0 ; i < n;i++){
        cin>>a[i];
        if(!chk[a[i]]){
            chk[a[i]]=1;
            num[idx++]=a[i];

        }


    }
    sort(num,num+idx);

    for(int i = 0 ; i< idx;i++){
        chk[num[i]]=i+1;
    }
    ll ans =0;
    for(int i =n-1;i>=0;i--){

        ll cur0=a[i];
        ll cur1=a[i]*k;
        ll cur2=cur1*k;

        int id0=chk[cur0];
        int id1=chk[cur1];
        int id2=chk[cur2];

        ans+=(query(1,id1)-query(1,id1-1));

       // cout<<"i:"<<i<<"\tans:"<<ans<<"\tcur0:"<<cur0<<"\tid0:"<<id0<<"\tcur1:"<<cur1<<"\tid1:"<<id1<<"\tcur2:"<<cur2<<"\tid2:"<<id2<<endl;


        if(id1){
            ll val1=(query(0,id1)-query(0,id1-1));
               // cout<<"\tval1:"<<val1<<endl;
            update(1,id0,val1);
        }

        update(0,id0,1);
    }
    cout<<ans<<"\n";
    return 0;
}


	  						 			 		  				   	  			