#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int m, n;
  void bfs(vector<vector<char>> &grid, int row, int col) {
    if (row < 0 || col < 0) return;               // beyond grid
    if (row >= this->m || col >= this->n) return; // beyond grid
    if (grid[row][col] == '0') return;            // if it is water

    grid[row][col] = '0'; // mark as water cause it is visited already

    bfs(grid, row, col + 1);
    bfs(grid, row, col - 1);
    bfs(grid, row + 1, col);
    bfs(grid, row - 1, col);
  }

  int numIslands(vector<vector<char>> &grid) {
    this->m = grid.size();
    this->n = grid.front().size();

    queue<int> q;

    // call bfs
    int islands = 0;
    for (int row = 0; row < this->m; row++) {
      for (int col = 0; col < this->n; col++) {
        if (grid[row][col] != '1') continue;

        this->bfs(grid, row, col);
        islands++;
      }
    }

    return islands;
  }
};
// class Solution {
// public:
//   vector<vector<bool>> visitedGrid;
//   int m, n;
//   void bfs(queue<int> &q, vector<vector<char>> &grid) {
//     int dr[4] = {1, -1, 0, 0};
//     int dc[4] = {0, 0, -1, 1};
//     while (!q.empty()) {
//       int row = q.front();
//       q.pop();
//       int col = q.front();
//       q.pop();
//       for (int i = 0; i < 4; i++) {
//         int rr = row + dr[i];
//         int cc = col + dc[i];

//         if (rr < 0 || cc < 0) continue;
//         if (rr >= this->m || cc >= this->n) continue;
//         if (grid[rr][cc] == '0') continue; // if it is water
//         if (visitedGrid[rr][cc]) continue; // if already visited

//         this->visitedGrid[rr][cc] = true;
//         q.push(rr);
//         q.push(cc);
//       }
//     }
//   }

//   int numIslands(vector<vector<char>> &grid) {
//     this->m = grid.size();
//     this->n = grid.front().size();
//     this->visitedGrid =
//         vector<vector<bool>>(this->m, vector<bool>(this->n, false));

//     queue<int> q;

//     // call bfs
//     int counter = 0;
//     for (int i = 0; i < this->m; i++) {
//       for (int j = 0; j < this->n; j++) {
//         if (visitedGrid[i][j]) continue;
//         if (grid[i][j] == '0') continue;

//         q.push(i);
//         q.push(j);

//         this->bfs(q, grid);
//         counter++;
//       }
//     }

//     return counter;
//   }
// };
int main(int argc, char const *argv[]) {
  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};
  //   vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
  //                                {'1', '1', '0', '1', '0'},
  //                                {'1', '1', '0', '0', '0'},
  //                                {'0', '0', '0', '0', '0'}};
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++)
      cout << grid[i][j] << ' ';
    cout << endl;
  }
  int result = Solution().numIslands(grid);

  cout << "Result: " << result << endl;
  return 0;
}
