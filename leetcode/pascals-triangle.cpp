#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    result.push_back({1});
    for (int i = 1; i < numRows; i++) {
      vector<int> temp;
      temp.reserve(i + 1);
      temp.push_back(1); // first
      for (int j = 1; j < i; j++)
        temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
      temp.push_back(1); // last
      result.push_back(temp);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> result = Solution().generate(10);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++)
      cout << result[i][j] << ' ';
    cout << endl;
  }

  return 0;
}
