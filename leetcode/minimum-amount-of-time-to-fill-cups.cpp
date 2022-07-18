#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int fillCups(vector<int> &amount) {
    int seconds = 0;
    int cold = amount[0], warm = amount[1], hot = amount[2];
    while (true) {
      if (amount[0] <= 0 && amount[1] <= 0 && amount[2] <= 0) return seconds;
      sort(amount.begin(), amount.end());
      amount[1]--;
      amount[2]--;
      seconds++;
    }
    return seconds;
  }
};
int main(int argc, char const *argv[]) {
  vector<int> cups = {5, 4, 4};

  int result = Solution().fillCups(cups);

  cout << "Result: " << result << endl;
  return 0;
}
