#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumXOR(vector<int> &nums) {
    int result = 0;

    for (int i = 0; i < nums.size(); i++) {
      result |= nums[i];
    }

    return result;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums = {3, 2, 4, 6};
  int result = Solution().maximumXOR(nums);

  cout << "RESULT: " << (result) << endl;
  return 0;
}

// 6 & 6 ^ 2
// 64 32 16 8 4 2 1
//  0  0  0 0 1 1 0 = 6
//  0  0  0 0 1 0 0 = 4
//  6^4 = 2
//  0  0  0 0 0 1 0 = 2
//  6 & 2 = 2
