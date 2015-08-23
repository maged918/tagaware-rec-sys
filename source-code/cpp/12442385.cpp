//Language: MS C++


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
int main(){
    unsigned int n;
    cin >> n;
    vector <unsigned int> p(n);
    
    list <unsigned int> l;  map <unsigned int, bool> mapp; map <unsigned int, int> mm;
    
    for (unsigned int ii = 0; ii < n; ii++){
        cin >> p[ii], mapp[p[ii]] = true;
    }
        
    for (unsigned int ii = 1; ii <= n; ii++){
        if (!mapp[ii]) 
            l.push_back(ii);}
        
    
    for (unsigned int i = 0; i < n; i++){
        if (p[i] > n){
            cout << l.front() << endl;
            l.pop_front();}
        else if (mm[p[i]] == 0 && i != n - 1){
            cout << p[i] << " ";
            mm[p[i]]++;}
        
        else if (mm[p[i]] == 0 && i == n - 1){
            cout << p[i] << endl;}
        
        else if (mm[p[i]] != 0 && i != n - 1){
            cout << l.front() << " ";
            l.pop_front();}
        else{
            cout << l.front() << endl;
            l.pop_front();}}
    return 0;
}