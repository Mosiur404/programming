#include <iostream>
#include <cmath>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); }
};
// class Solution {
// public:
//   bool isPowerOfTwo(int n) {

//     switch (n) {
//     case 0:
//       return false;
//       break;
//     case 1:
//       return true;
//       break;
//     case 2:
//       return true;
//       break;
//     default:
//       long long l = n;
//       return !(l & (l - 1));
//       break;
//     }
//   }
// };
int main(int argc, char const *argv[]) {
  bool result = Solution().isPowerOfTwo(-2147483648);

  cout << (result ? "TRUE" : "FALSE") << endl;
  return 0;
}
