//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;
#define llint long long int

struct data{
  int index;
  int value;
};

bool compareFunctionInc(data a, data b){
  if (a.index < b.index) return true;
  else return false;
}

bool compareFunctionDec(data a, data b){
  if (a.index > b.index) return true;
  else return false;
}


int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<struct data> posArray;
  vector<struct data> negArray;

  for (int i = 0 ; i < n ; i++){
    int tmpindex;
    cin >> tmpindex;
    int tmpval;
    cin >> tmpval;

    struct data d;
    d.index = tmpindex;
    d.value = tmpval;

    if (tmpindex > 0) {
      posArray.push_back(d);
    }
    else{
      negArray.push_back(d);
    }
  }

  sort(posArray.begin(), posArray.end(), compareFunctionInc);
  sort(negArray.begin(), negArray.end(), compareFunctionDec);

  int size = min( posArray.size(), negArray.size() );

  int index = 0;
  llint sum = 0;
  while (index < size){
    sum = sum + posArray[index].value + negArray[index].value;
    index++;
  }
  if (size < posArray.size()){
    sum = sum + posArray[index].value;
  }
  else if (size < negArray.size()){
    sum = sum + negArray[index].value;
  }
  cout<<sum<<endl;

  return 0;
}