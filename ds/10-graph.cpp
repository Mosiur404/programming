#include <E:\Github\competeitve\ds\include\color.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <array>
using namespace std;
// #Shortest Path to some node:
// ->Breadth first BFS, Dijkastra algorithm, Belmann Ford algorithm, A star
// #Does path exist
// ->Union find data structure, BFS, DFS
// #Negative cycle (Trap)
// Bellman Ford, Warshall
// #Strongly connected components (All vertex in cycle can reach others)
// Tarzan & Kosarazu's algorithm
// #Shortest path to same node:
// Travelling salesman, Held-Karp, Branch & bound, Many approxiamation algorithm
// #Articulation point (Joint) Weak points, bottlenecks, bridges
// #Minimum spanning tree -> Tree with least costs
// Krushkal, prims, Boruvkas algorithm
// #Network flow (Max flow)
// SSSP(Single source shortest path) on DAG

struct Node {
  int id;
  list<pair<int, int>> edges;
};
class AdjacencyList {
private:
  const int listSize;
  vector<Node> adjacencyList;

public:
  AdjacencyList *push(Node newNode) {
    this->adjacencyList.push_back(newNode);
    return this;
  }

  void _DFS(bool v[], Node next, vector<int> &visitedNodes) {
    int currentIndex = next.id - 1;
    if (v[currentIndex]) return;
    v[currentIndex] = true;
    for (pair<int, int> neighbour : next.edges)
      this->_DFS(v, this->adjacencyList.at(neighbour.first - 1), visitedNodes);
    visitedNodes.push_back(next.id);
  }
  // DFS
  void DFS() {
    bool visited[this->listSize] = {false};
    vector<int> visitedNodes;
    this->_DFS(visited, this->adjacencyList.front(), visitedNodes);
    for (int id : visitedNodes)
      cout << this->adjacencyList[id - 1].id << ' ';
    cout << endl;
  }
  vector<int> topologicalSort() {
    vector<int> ordering = vector<int>(this->listSize, 0);
    bool v[this->listSize] = {false};
    int index = this->listSize - 1;
    for (int i = 0; i < this->listSize; i++) {
      if (v[i] == false) {
        vector<int> visitedNodes;
        this->_DFS(v, this->adjacencyList.front(), visitedNodes);
        for (int id : visitedNodes) {
          ordering[index] = id;
          index--;
        }
      }
    }
    return ordering;
  }
  bool BFS(int id) {
    int nodeSize = this->adjacencyList.size();
    bool visited[nodeSize] = {false};
    queue<Node> q;
    if (!this->adjacencyList.empty()) q.push(this->adjacencyList.front());

    while (!q.empty()) {
      Node currentItem = q.front();
      q.pop();
      if (currentItem.id == id) return true;
      for (pair<int, int> adj : currentItem.edges) {
        if (visited[currentItem.id] == false) {
          q.push(this->adjacencyList[adj.first - 1]);
          visited[currentItem.id] = true;
        }
      }
    }
    return false;
  }

  void pathRelaxation(int id = 1) {
    vector<int> relaxedPath = vector<int>(this->listSize, INT_MAX); // infinity
    relaxedPath[id - 1] = 0;                                        // start 0
    vector<int> topologicalOrdeing = this->topologicalSort();

    for (int currentNodeId : topologicalOrdeing) {
      Node currentNode = this->adjacencyList[currentNodeId - 1];
      for (pair<int, int> adj : currentNode.edges) {
        int currentNodeIndex = currentNode.id - 1;
        int currentEdgeIndex = adj.first - 1;

        int distance = relaxedPath[currentNodeIndex] + adj.second;
        relaxedPath[currentEdgeIndex] =
            min(relaxedPath[currentEdgeIndex], distance);
      }
    }
    cout << "Relaxed: " << endl;
    for (int item : topologicalOrdeing)
      cout << (char)(item + 64) << '\t';
    cout << endl;
    for (int weights : relaxedPath)
      cout << weights << '\t';
    cout << endl;
  }
  // extra
  void print() {
    for (Node item : this->adjacencyList) {
      cout << '(' << item.id << ')';
      for (pair<int, int> adj : item.edges) {
        cout << '\t' << "〇--- " << adj.second << " --->" << adj.first;
      }
      cout << endl;
    }
  }

  AdjacencyList(int l = 0) : listSize(l) { this->adjacencyList.reserve(l); }
  ~AdjacencyList() {}
};

/*
 * AdjacencyMatrix
 */
class AdjacencyMatrix {
private:
  const int matrixSize;
  vector<vector<char>> adjacencyMatrix;
  vector<vector<bool>> visitedMatrix;

public:
  AdjacencyMatrix *push(int row, int col, int val) {
    this->adjacencyMatrix[row][col] = val;
    return this;
  }
  // BFS
  void exploreNeighbours(int r, int c, queue<pair<int, int>> &gq, char deadEnd,
                         int &nodesInNextLayer) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
      int row = r + dr[i];
      int column = c + dc[i];
      if (row < 0 || column < 0) continue; // not in array
      if (row >= this->matrixSize || column >= this->matrixSize) continue;

      if (this->visitedMatrix[row][column] == true) continue;
      if (this->adjacencyMatrix[row][column] == deadEnd) continue;
      this->visitedMatrix[row][column] = true;
      gq.push({row, column});
      nodesInNextLayer++;
    }
  }
  bool BFS(int startRow, int startColumn) {
    char end = 'E', deadEnd = '#';
    int moveCount = 0, nodesLeftInLayer = 1, nodesInNextLayer = 0;
    bool reachedEnd = false;

    queue<pair<int, int>> gq;
    gq.push({startRow, startColumn}); // start
    this->visitedMatrix[startRow][startColumn] = true;
    while (!gq.empty()) {
      auto [row, column] = gq.front();
      gq.pop();

      char currentValue = this->adjacencyMatrix[row][column];
      if (currentValue == end) {
        reachedEnd = true;
        cout << "Row: " << row << " Column: " << column << endl;
        break;
      };
      this->exploreNeighbours(row, column, gq, deadEnd, nodesInNextLayer);
      nodesLeftInLayer--;
      if (nodesLeftInLayer == 0) {
        nodesLeftInLayer = nodesInNextLayer;
        nodesInNextLayer = 0;
        moveCount++;
      }
    }
    if (reachedEnd) {
      cout << "Moves: " << moveCount << endl;
      return true;
    }
    return false;
  }
  void print() {
    cout << "INDEX" << '\t';
    for (int r = 0; r < this->matrixSize; r++)
      cout << r << '\t';
    cout << endl;
    cout << endl;
    for (int r = 0; r < this->matrixSize; r++) {
      cout << r << '\t';
      for (int c = 0; c < this->matrixSize; c++) {
        if (this->visitedMatrix[r][c])
          cout << dye::aqua(this->adjacencyMatrix[r][c]) << '\t';
        else
          cout << dye::purple(this->adjacencyMatrix[r][c]) << '\t';
      }
      cout << endl;
    }
  }
  AdjacencyMatrix(int g = 0) : matrixSize(g) {
    // assign  matrix
    this->adjacencyMatrix = vector<vector<char>>(
        this->matrixSize, vector<char>(this->matrixSize, '-'));
    this->visitedMatrix = vector<vector<bool>>(
        this->matrixSize, vector<bool>(this->matrixSize, false));
  }
  ~AdjacencyMatrix() {}
};

int main(int argc, char const *argv[]) {
  AdjacencyList *graphList = new AdjacencyList(10);
  graphList->push({1, {{2, 0}, {4, 0}, {3, 0}}})
      ->push({2, {{6, 0}}})
      ->push({3, {{8, 0}}})
      ->push({4, {{7, 0}}})
      ->push({5})
      ->push({6, {{10, 0}}})
      ->push({7, {{9, 0}}})
      ->push({8, {{5, 0}}})
      ->push({9})
      ->push({10});

  graphList->print();

  cout << "Search: " << (graphList->BFS(12) ? "Yes" : "No") << endl;
  cout << "Search: " << endl;
  graphList->DFS();

  cout << "Ordering: ";
  for (int item : graphList->topologicalSort()) {
    cout << item << ' ';
  }
  cout << endl;
  cout << endl << endl;

  // graph matrix
  AdjacencyMatrix *graphMatrix = new AdjacencyMatrix(6);
  cout << "Graph: " << endl;
  graphMatrix->push(0, 3, '#')
      ->push(1, 1, '#')
      ->push(1, 5, '#')
      ->push(2, 1, '#')
      ->push(3, 2, '#')
      ->push(3, 3, '#')
      ->push(4, 0, '#')
      ->push(4, 2, '#')
      ->push(4, 5, '#')
      ->push(4, 3, 'E');
  graphMatrix->BFS(0, 0);
  graphMatrix->print();

  // another adjacency list
  cout << "Another Graph: " << endl;
  AdjacencyList *graphList1 = new AdjacencyList(8);
  graphList1->push({1, {{2, 3}, {3, 6}}})
      ->push({2, {{3, 4}, {4, 4}, {5, 11}}})
      ->push({3, {{4, 8}, {7, 11}}})
      ->push({4, {{5, -4}, {6, 5}, {7, 2}}})
      ->push({5, {{8, 9}}})
      ->push({6, {{8, 1}}})
      ->push({7, {{8, 2}}})
      ->push({8, {}});
  graphList1->print();

  graphList1->pathRelaxation(1);
  return 0;
}