//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int pos;
    int apple;
};

bool cmpR(node a,node b){
    return a.pos<b.pos;
}

bool cmpL(node a,node b){
    return a.pos>b.pos;
}
int main(){
    int n;
    node left[108];
    node right[108];
    int numOfLeft;
    int numOfRight;
    while(cin>>n){
        int pos,apple;
        numOfLeft=0;
        numOfRight=0;
        for(int i=1;i<=n;i++){
            cin>>pos>>apple;
            if(pos<0){
                left[++numOfLeft].pos=pos;
                left[numOfLeft].apple=apple;
            }
            else{
                right[++numOfRight].pos=pos;
                right[numOfRight].apple=apple;
            }
        }
        sort(left+1,left+1+numOfLeft,cmpL);
        sort(right+1,right+numOfRight+1,cmpR);
        int answer=0;
        if(numOfLeft==numOfRight){
            for(int i=1;i<=numOfLeft;i++){
                answer=answer+left[i].apple+right[i].apple;
            }
        }
        else{
            int temp=min(numOfLeft,numOfRight);
            if(numOfLeft>numOfRight){
                for(int i=1;i<=temp+1;i++){
                    answer+=left[i].apple;
                }
                for(int i=1;i<=temp;i++){
                    answer+=right[i].apple;
                }
            }
            else{
                for(int i=1;i<=temp+1;i++){
                    answer+=right[i].apple;
                }
                for(int i=1;i<=temp;i++){
                    answer+=left[i].apple;
                }
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}
