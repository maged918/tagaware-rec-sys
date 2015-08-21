//Language: GNU C++11


#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int N;                        // 1 <= N <= 4000
  cin >> N;

  vector<vector<int>> choose{vector<int>{1}}; // choose[0][0] = 1
  for (int i = 1; i <= N; ++i) {
    choose.push_back(vector<int>{1});
    for (int j = 1; j < i; ++j) {
      choose.back().push_back((choose[i-1][j] + choose[i-1][j-1]) % MOD);
    }
    choose.back().push_back(1);
  }
  
  // first index is number of elements in the set, second index is number of equivalence classes
  vector<vector<int>> equivalenceRelations{vector<int>{1}}; // no equivalence relations if 0 equivalence classes and 0 elements
  for (int n = 1; n < N; ++n) {   // size of set
    equivalenceRelations.push_back(vector<int>{0}); // no equivalence relations if 0 equivalence classes    
    for (int k = 1; k < n; ++k) {
      // assign it to an existing class of the old n - 1 elements, k options, for each equivalence relation
      // plus creating a new equivalence class
      equivalenceRelations.back().push_back(( ((long long) equivalenceRelations[n-1][k]*k) % MOD + equivalenceRelations[n-1][k-1] ) % MOD);
    }
    equivalenceRelations.back().push_back(1); // 1 equivalence relation if n equivalence classes, each element equivalent to itself
  }
  
  vector<long long> equivalenceRelationsBySetSize;
  for (int i = 0; i < N; ++i) {
    int relations = 0;
    for (int j : equivalenceRelations[i]) {
      relations += j; relations %= MOD;
    }
    equivalenceRelationsBySetSize.push_back(relations);
  }
  
  int binaryRelations = 0;      // relations that are symmetric, transitive, but not reflexive
  for (int i = 1; i <= N; ++i) {
    // choose a set to zero out, the reset of the elements make a proper equivalence relation
    binaryRelations += (equivalenceRelationsBySetSize[N-i]*choose[N][i]) % MOD;
    binaryRelations %= MOD;
  }

  cout << binaryRelations << endl;  
  return 0;
}



  // vector<vector<vector<int>>> partitionMemo;
  // partitionMemo.push_back(vector<vector<int>>());
  // for (int i = 1; i < N; ++i) {
  //   partitionMemo.push_back(vector<vector<int>>{vector<int>{i}}); // the number itself
  //   for (vector<int> p : partitionMemo[i - 1]) {
  //     // avoid repeating any partitions by generating decreasing sequences
  //     if (p.size() >= 2 && p.back() < *(p.rbegin() + 1)) {
  //       partitionMemo.back().emplace_back(p);
  //       ++partitionMemo.back().back().back();
  //     }
  //     partitionMemo.back().emplace_back(p);
  //     partitionMemo.back().back().push_back(1); // add a 1 to everything
  //   }
  // } 
