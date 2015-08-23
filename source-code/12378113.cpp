//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int> > num;
int n;

// el primero que cumple que el valor es val (ademas p < pos)
int buscoMenor (int val, int pos) {
    if (num[0].first > val || num[n-1].first < val)
        return -1;
    
    int i = 0, d = n-1, m;
    while ( d - i > 1 ) {
        // cerr << i << " " << d << endl;
        m = (d+i)/2;
        if (num[m].first > val || (num[m].first == val && m>0 && num[m-1].first == val))
            d = m;
        else
            i = m;
    }
    // cerr << i << " " << d << endl;
    if (num[i].first == val && num[i].second < pos)
        return i;
    if (num[d].first == val && num[d].second < pos)
        return d;
    return -1;
}

// el ultimo que cumple que la posicion es val y la posicion es a lo sumo pos
int buscoMayor (int val, int pos) {
    if (num[0].first > val || num[n-1].first < val)
        return -1;
    
    int i = 0, d = n-1, m;
    while ( d - i > 1 ) {
        // cerr << i << " " << d << endl;
        m = (d+i)/2;
        if (num[m].first < val)
            i = m;
        else if (num[m].first == val && num[m].second < pos && m+1<n && num[m+1].first == val && num[m+1].second < pos)
            i = m;
        else
            d = m;
    }
    // cerr << i << " " << d << endl;
    if (num[d].first == val && num[d].second < pos)
        return d;
    if (num[i].first == val && num[i].second < pos)
        return i;
    return -1;
}


// el primero que cumple que el valor es val y la posicion es como minimo pos
int buscoMenor2 (long long int val, int pos) {
    if (num[0].first > val || num[n-1].first < val)
        return -1;
    
    int i = 0, d = n-1, m;
    while ( d - i > 1 ) {
        // cerr << i << " " << d << endl;
        m = (d+i)/2;
        // si con d me pase o hay alguno valido antes
        if (num[m].first > val)
            d = m;
        else if (num[m].first == val && num[m].second > pos && m>0 && num[m-1].first == val && num[m-1].second > pos)
            d = m;
        else
            i = m;
    }
    // cerr << i << " " << d << endl;
    if (num[i].first == val && num[i].second > pos)
        return i;
    if (num[d].first == val && num[d].second > pos)
        return d;
    return -1;
}

// el ultimo que cumple que la posicion es val (ademas p > pos)
int buscoMayor2 (long long int val, int pos) {
    if (num[0].first > val || num[n-1].first < val)
        return -1;
    
    int i = 0, d = n-1, m;
    while ( d - i > 1 ) {
        // cerr << i << " " << d << endl;
        m = (d+i)/2;
        if (num[m].first < val || (num[m].first == val && m+1<n && num[m+1].first == val))
            i = m;
        else
            d = m;
    }
    // cerr << i << " " << d << endl;
    if (num[d].first == val && num[d].second > pos)
        return d;
    if (num[i].first == val && num[i].second > pos)
        return i;
    return -1;
}

int main () {
    #ifdef ACMTUYO 
        freopen("c.in", "r", stdin);
    #endif
    
    int k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        
        num.push_back(make_pair(x, i));
    }
    sort(num.begin(), num.end());
    
    long long result = 0;
    for (int i = 0; i < n; i++) {
        int val = num[i].first;
        int pos = num[i].second;
        
        // busqueda binaria buscando la cant de val/k con pos menor
        if (val%k != 0)
            continue;
            
        // cerr << pos << endl;
        int menor = buscoMenor(val/k, pos);
        int mayor = buscoMayor(val/k, pos);

        // cerr << i << " " << menor << " " << mayor << endl;   

        if (menor == -1 || mayor == -1)
            continue;
            
        int a = mayor - menor + 1;
        
        // cerr << a << " ---------------------------------" << endl;
        
        // bb buscando la cant de val*k con pos mayor
        menor = buscoMenor2(((long long) val)*((long long) k), pos);
        mayor = buscoMayor2(((long long) val)*((long long) k), pos);
        // cerr << ((long long) val)*((long long) k) << endl;
        
        // cerr << i << " " << menor << " " << mayor << endl;
    
        if (menor == -1 || mayor == -1)
            continue;
        
        result += ((long long) a) * (mayor - menor + 1);
    }
    cout << result << endl;
    return 0;
}   
