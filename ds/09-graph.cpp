#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Node {
  int id;
  list<int> edges;
};

class Graph {
private:
  vector<Node> adjacencyList;

public:
  Graph *push(Node newNode) {
    this->adjacencyList.push_back(newNode);
    return this;
  }
  Graph(int n = 1) { this->adjacencyList.reserve(n); }
  ~Graph() {}
};

int main(int argc, char const *argv[]) {
  Graph *graph = new Graph();
  graph->push({1, {2, 4, 3}});
  return 0;
}