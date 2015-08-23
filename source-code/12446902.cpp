//Language: GNU C++11


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,track=1,sz;
    vector<int> red;
    cin>>n;
    bool occ[n+1];
    int a[n];
    for(int i=1;i<=n;i++)
        occ[i]=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>n||occ[a[i]])
            red.push_back(i);
        if(a[i]<=n)
            occ[a[i]]=true;
    }
    sz=red.size();
    for(int i=0;i<sz;i++){
        while(occ[track]){
            track++;
        }
        a[red[i]]=track;
        occ[track]=true;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}