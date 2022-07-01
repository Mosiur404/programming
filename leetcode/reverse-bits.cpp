#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    // 00000010100101000001111010011100
    // 00111001011110000010100101000000
    for (int i = 0; i < 32; i++) {
      cout << (!!(n & (1 << i))) << ' ';
      result |= (!!(n & (1 << i)) << (31 - i));
    }
    cout << (uint32_t)(1 << 31) << ' ';
    cout << endl;
    return result;
  }
};
int main(int argc, char const *argv[]) {
  uint32_t nums = 43261596;
  uint32_t result = Solution().reverseBits(nums);

  cout << "RESULT: " << (result) << endl;
  return 0;
}
