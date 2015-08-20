//Language: GNU C++11


#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <ctime>

using namespace std;

// 3 primes numbers, probability says it's unlikely 2 different numbers will be different after modding 3 times
const int MOD_A = 1000000207;
const int MOD_B = 1000000007;
const int MOD_C = 999999733;

namespace phillypham {
  class priority_queue {
  private:
    int keysSize;
    vector<int> keys;
    vector<long long> values;
    unordered_map<int, int> keyToIdx;
    int parent(int idx) {
      return (idx + 1)/2 - 1;
    }
    int left(int idx) {
      return 2*(idx+1) - 1;
    }
    int right(int idx) {
      return 2*(idx+1);
    }
    void heap_swap(int i, int j) {
      if (i != j) {
        keyToIdx[keys[j]] = i;
        keyToIdx[keys[i]] = j;
        swap(values[j], values[i]);
        swap(keys[j], keys[i]);
      }
    }
    void max_heapify(int idx) {
      int lIdx = left(idx);
      int rIdx = right(idx);
      int smallestIdx = idx;
      if (lIdx < keysSize && values[lIdx] < values[smallestIdx]) {
        smallestIdx = lIdx;
      }
      if (rIdx < keysSize && values[rIdx] < values[smallestIdx]) {
        smallestIdx = rIdx;
      }
      if (smallestIdx != idx) {
        heap_swap(smallestIdx, idx);
        max_heapify(smallestIdx);
      } 
    }
    
    void min_heapify(int idx)  {
      while (idx > 0 && values[parent(idx)] > values[idx]) {
        heap_swap(parent(idx), idx);
        idx = parent(idx);
      }
    }
    
  public:
    priority_queue(int N) {
      keysSize = 0;
      keys.clear(); keys.reserve(N);
      values.clear(); values.reserve(N);
      keyToIdx.clear(); keyToIdx.reserve(N);
    }
    
    void push(int key, long long value) {
      // if (keyToIdx.count(key)) throw logic_error("key " + ::to_string(key) + " already exists");
      int idx = keysSize; ++keysSize;
      if (keysSize > keys.size()) {
        keys.push_back(key);
        values.push_back(value);
      } else {
        keys[idx] = key;
        values[idx] = value;
      }   
      keyToIdx[key] = idx;
      min_heapify(idx);      
    }

    void increase_key(int key, long long value) {
      // if (!keyToIdx.count(key)) throw logic_error("key " + ::to_string(key) + " does not exist");
      // if (values[keyToIdx[key]] > value) throw logic_error("value " + ::to_string(value) + " is not an increase");
      values[keyToIdx[key]] = value;
      max_heapify(keyToIdx[key]);
    }

    void decrease_key(int key, long long value) {
      // if (!keyToIdx.count(key)) throw logic_error("key " + ::to_string(key) + " does not exist");
      // if (values[keyToIdx[key]] < value) throw logic_error("value " + ::to_string(value) + " is not a decrease");
      values[keyToIdx[key]] = value;
      min_heapify(keyToIdx[key]);       
    }

    void pop() {
      if (keysSize > 0) {
        heap_swap(0, --keysSize);
        keyToIdx.erase(keys[keysSize]);       
        if (keysSize > 0) max_heapify(0);
      } else {
        throw logic_error("priority queue is empty");
      }
    }
    
    int top() {
      if (keysSize > 0) {
        return keys.front();
      } else {
        throw logic_error("priority queue is empty");
      }
    }    

    int size() {
      return keysSize;
    }

    bool empty() {
      return keysSize == 0;
    }

    int at(int key) {
      return values[keyToIdx[key]];
    }

    int count(int key) {
      return keyToIdx.count(key);
    }

    string to_string() {
      ostringstream out;
      copy(keys.begin(), keys.begin() + keysSize, ostream_iterator<int>(out, " "));
      out << '\n';
      copy(values.begin(), values.begin() + keysSize, ostream_iterator<int>(out, " "));
      out << '\n';      
      return out.str();
    }    
  };
}

vector<pair<long long, unordered_set<int>>> computeShortestPath(int s, const vector<unordered_map<int, pair<int, int>>> &edgeList) {
  int N = edgeList.size();
  vector<pair<long long, unordered_set<int>>> distance(N, make_pair(LLONG_MAX/3, unordered_set<int>()));
  phillypham::priority_queue pq(N);
  distance[s].first = 0;
  pq.push(s, 0);
  while (!pq.empty()) {  
    int currentVertex = pq.top(); pq.pop();
    long long currentDistance = distance[currentVertex].first;
    // relax step
    for (pair<int, pair<int, int>> entry : edgeList[currentVertex]) {
      int nextVertex = entry.first; int length = entry.second.first;
      long long newDistance = currentDistance + length;
      if (distance[nextVertex].first > newDistance) {
        distance[nextVertex].first = newDistance;
        distance[nextVertex].second.clear();
        distance[nextVertex].second.insert(currentVertex);
        if (pq.count(nextVertex)) {
          pq.decrease_key(nextVertex, newDistance);
        } else {
          pq.push(nextVertex, newDistance);
        }
      } else if (distance[nextVertex].first == newDistance) {        
        distance[nextVertex].second.insert(currentVertex);
      }
    }
  }
  return distance;
}

tuple<int, int, int> addPathTuples(tuple<int, int, int> a, tuple<int, int, int> b) {
  return make_tuple((get<0>(a) + get<0>(b)) % MOD_A, (get<1>(a) + get<1>(b)) % MOD_B, (get<2>(a) + get<2>(b)) % MOD_C);
}

tuple<int, int, int> multiplyPathTuples(tuple<int, int, int> a, tuple<int, int, int> b) {
  long long a0 = get<0>(a);
  long long a1 = get<1>(a);
  long long a2 = get<2>(a);
  return make_tuple((a0*get<0>(b)) % MOD_A, (a1*get<1>(b)) % MOD_B, (a2*get<2>(b)) % MOD_C);
}

vector<tuple<int, int, int>> countPaths(int s, 
                                        const vector<pair<long long, unordered_set<int>>> &distances,
                                        const vector<pair<long long, unordered_set<int>>> &children) {
  // assume only edges that make shortest paths are included
  int N = children.size();
  vector<tuple<int, int, int>> pathCounts(N, make_tuple(0, 0, 0)); // store as tuple, basically modular hash function
  pathCounts[s] = make_tuple(1, 1, 1);
  phillypham::priority_queue pq(N);
  pq.push(s, 0);
  while (!pq.empty()) {
    int currentVertex = pq.top(); pq.pop();  
    for (int nextVertex : children[currentVertex].second) {
      pathCounts[nextVertex] = addPathTuples(pathCounts[currentVertex], pathCounts[nextVertex]);
      if (!pq.count(nextVertex)) {
        pq.push(nextVertex, distances[nextVertex].first);
      }
    }    
  }
  return pathCounts;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N, M, s, t; // number of nodes, edges, source, and target
  cin >> N >> M >> s >> t;
  --s; --t;                     // 0 indexing
  vector<tuple<int, int, int>> edges;
  vector<unordered_map<int, pair<int, int>>> edgeList(N);
  vector<unordered_map<int, pair<int, int>>> reverseEdgeList(N);
  for (int m = 0; m < M; ++m) { // read in edges
    int a, b, l;
    cin >> a >> b >> l;
    --a; --b;
    edges.emplace_back(a, b, l);
    if (!edgeList[a].count(b) || edgeList[a][b].first > l) {
      edgeList[a][b] = make_pair(l, 1);
      reverseEdgeList[b][a] = make_pair(l, 1);
    } else if (edgeList[a][b].first == l) {
      ++edgeList[a][b].second;
      ++reverseEdgeList[b][a].second;
    }
  } 
  vector<pair<long long, unordered_set<int>>> distanceFromSource = computeShortestPath(s, edgeList);
  vector<pair<long long, unordered_set<int>>> distanceFromTarget = computeShortestPath(t, reverseEdgeList);
  vector<tuple<int, int, int>> pathCounts = countPaths(s, distanceFromSource, distanceFromTarget);
  vector<tuple<int, int, int>> backPathCounts = countPaths(t, distanceFromTarget, distanceFromSource);
  for (int i = 0; i < N; ++i) pathCounts[i] = multiplyPathTuples(pathCounts[i], backPathCounts[i]);
    
  long long shortestDistance = distanceFromSource[t].first;
  tuple<int, int, int> shortestPaths = pathCounts[s];
  for (tuple<int, int, int> edge : edges) {
    long long pathDistance = distanceFromSource[get<0>(edge)].first + get<2>(edge) + distanceFromTarget[get<1>(edge)].first;
    if (pathDistance == shortestDistance && // path is shortest
        pathCounts[get<0>(edge)] == shortestPaths && // every path goes through from node
        pathCounts[get<1>(edge)] == shortestPaths && // every path goes through to node
        distanceFromSource[get<1>(edge)].second.size() == 1 && // only paths come from the from node
        edgeList[get<0>(edge)][get<1>(edge)].second == 1) {
      cout << "YES" << '\n';
    } else if (pathDistance - get<2>(edge) + 1 < shortestDistance) {
      cout << "CAN" << ' ' << (pathDistance - shortestDistance) + 1 << '\n';
    } else {
      // which will happen if the city is unconnected since the edge won't be big enough to overcome the big distance
      cout << "NO" << '\n';
    }
  }
  cout << flush;
  return 0;
}
