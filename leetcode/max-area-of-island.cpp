#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int m, n;
  int bfs(queue<int> &q, vector<vector<int>> &grid) {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int moveCount = 1;
    while (!q.empty()) {
      int row = q.front();
      q.pop();
      int col = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int rr = row + dr[i];
        int cc = col + dc[i];

        if (rr < 0 || cc < 0) continue;
        if (rr >= this->m || cc >= this->n) continue;
        if (grid[rr][cc] == 0) continue; // if it is water
        if (!grid[rr][cc]) continue;     // if already visited

        grid[rr][cc] = 0; // make it unusable
        q.push(rr);
        q.push(cc);
        moveCount++;
      }
    }
    return moveCount;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    this->m = grid.size();
    this->n = grid.front().size();
    queue<int> q;

    // call bfs
    int maxMoves = 0;
    for (int i = 0; i < this->m; i++) {
      for (int j = 0; j < this->n; j++) {
        if (grid[i][j] == 0) continue;

        grid[i][j] = 0;
        q.push(i);
        q.push(j);
        maxMoves = max(this->bfs(q, grid), maxMoves);
      }
    }
    return maxMoves;
  }
};

// class Solution {
// public:
//   int m, n;
//   int bfs(vector<vector<int>> &grid, int row, int col, int &count) {
//     if (row < 0 || col < 0) return count;
//     if (row >= this->m || col >= this->n) return count;
//     if (grid[row][col] == 0) return count; // if it is water

//     count++; // if already visited

//     grid[row][col] = 0; // make it unusable

//     bfs(grid, row, col + 1, count);
//     bfs(grid, row, col - 1, count);
//     bfs(grid, row + 1, col, count);
//     bfs(grid, row - 1, col, count);

//     return count;
//   }

//   int maxAreaOfIsland(vector<vector<int>> &grid) {
//     this->m = grid.size();
//     this->n = grid.front().size();

//     // call bfs
//     int maxMoves = 0;
//     for (int i = 0; i < this->m; i++) {
//       for (int j = 0; j < this->n; j++) {
//         if (grid[i][j] == 0) continue;

//         int t = 0;
//         maxMoves = max(this->bfs(grid, i, j, t), maxMoves);
//       }
//     }
//     return maxMoves;
//   }
// };

int main() {
  vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  //   vector<vector<int>> grid = {{'1', '1', '1', '1', '0'},
  //                                {'1', '1', '0', '1', '0'},
  //                                {'1', '1', '0', '0', '0'},
  //                                {'0', '0', '0', '0', '0'}};
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++)
      cout << grid[i][j] << ' ';
    cout << endl;
  }
  int result = Solution().maxAreaOfIsland(grid);

  cout << "Result: " << result << endl;
  return 0;
}
