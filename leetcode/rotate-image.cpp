#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size() - 1;

    for (int row = 0; row <= n; row++) {
      for (int column = 0; column <= n; column++) {
        int temp = matrix[row][column];
        matrix[row][column] = matrix[column][row];
        matrix[column][row] = temp;
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << ' ';
    cout << endl;
  }
  Solution().rotate(matrix);

  cout << endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << ' ';
    cout << endl;
  }

  cout << endl;
  return 0;
}
