#include <iostream>
#include <list>
using namespace std;

struct Node {
  int id;
  list<int> edges;
};

class Graph {

public:
  Graph() {}
  ~Graph() {}
};

int main(int argc, char const *argv[]) {
  Graph *graph = new Graph();
  return 0;
}