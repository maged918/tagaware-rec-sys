//Language: GNU C++11


#include <iostream>
#include <set>
using namespace std;

#define REP(a,n) for(int a=0;a<n;++a)
#define P(a) cerr<<#a<<"="<<(a)<<endl;

char s[300000+1];

set<pair<int,int> > p;

int r=0;

void add(int i,int j){
    if(i<j){
        r+=j-i-1;
        p.insert(make_pair(i,j));
    }
}

void sub(set<pair<int,int> >::iterator i){
    r-= (i->second - i->first -1);
    p.erase(i);
}

int main(){
    int n,m;
    cin>>n>>m;
    cin>>s;

    int c=0;
    REP(a,n){
        if(s[a]=='.'){
            ++c;
        }else{
            if(c>0){
                add(a-c,a);
            }
            c=0;
        }
    }
    if(c>0){
        add(n-c,n);
    }
    c=0;

    REP(a,m){
        //P(a);
        //P(s);
        //P(r);
        //for(auto b:p){
        //    P(b.first);
        //    P(b.second);
        //}
        

        int x;
        char c;
        cin>>x>>c;
        --x;

        if(s[x]!='.' && c!='.'){
            cout<<r<<endl;
            continue;
        }
        if(s[x]=='.' && c=='.'){
            cout<<r<<endl;
            continue;
        }

        if(p.empty()){
            add(x,x+1);
            cout<<r<<endl;
            continue;
        }

        set<pair<int,int> >::iterator i;
        i=p.lower_bound(make_pair(x,x));
        if(i==p.end())--i;


        if(s[x]=='.' && c!='.'){
            s[x]=c;
            REP(q,2){
                if(i->first<=x && x<i->second){
                    sub(i);
                    int fir=i->first,sec=i->second;
                    add(fir,x);
                    add(x+1,sec);
                    break;;
                }
                if(x<i->first && i!=p.begin()){
                   --i;
                   continue;
                }
                if(i->second<x && i!=p.end()){
                   ++i;
                   continue;
                }
            }
        }else{
            s[x]=c;
            bool passed=0;
            REP(q,2){

               if(i->first-1==x){
                    passed=1;
                    int fir=i->first,sec=i->second;
                    if(i!=p.begin()){
                        auto j=i;
                        --j;
                        if(fir-1==j->second){
                            add(j->first,sec);
                            sub(i);
                            sub(j);
                        }else{
                            add(fir-1,sec);
                            sub(i);
                        }
                    }else{
                        add(fir-1,sec);
                        sub(i);
                    }
                    break;
                }

                if(i->second==x){
                    passed=1;
                    int fir=i->first,sec=i->second;
                    if(i!=p.end()){
                        auto j=i;
                        ++j;
                        if(sec==j->first){
                            add(fir,j->second);
                            sub(i);
                            sub(j);
                        }else{
                            add(fir,sec+1);
                            sub(i);
                        }
                    }else{
                        add(fir,sec+1);
                        sub(i);
                    }
                    break;
                }
                    
                if(x<i->first && i!=p.begin()){
                   --i;
                   continue;
                }
                if(i->second<x && i!=p.end()){
                   ++i;
                   continue;
                }
            }
            if(!passed){
                add(x,x+1);
            }
        }
        cout<<r<<endl;
    }
    return 0;
}
