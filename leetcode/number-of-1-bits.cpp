#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int result = 0;
    while (n) {
      n &= (n - 1);
      result++;
    }

    return result;
  }
};
// class Solution {
// public:
//   int hammingWeight(uint32_t  n) {
//     unsigned int result = 0;
//     for (int i = 0; i < 32; i++)
//       if (!!(n & (1 << i))) result++;

//     return result;
//   }
// };

int main(int argc, char const *argv[]) {
  int nums = 4294967293;
  int result = Solution().hammingWeight(nums);
  bitset<32> x = 3;
  cout << x << endl;
  cout << "RESULT: " << (result) << endl;
  return 0;
}
