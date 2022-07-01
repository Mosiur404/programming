#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#define log(x) std::cout << x << std::endl;
#define logBit(x) std::cout << std::bitset<8 * sizeof(x)>(x) << std::endl;
using namespace std;

class BitManager {
private:
public:
  int getBit(int item, int position) { return (item & (1 << position)) == 0; }
  int setBit(int item, int position) { return (item | (1 << position)); }
  int clearBit(int item, int position) { return (item & ~(1 << position)); }
  bool isPowerOfTwo(int num) { return (num & (num - 1)) == 0; }
  bool numberOfOnes(int num) {
    int count = 0;
    while (num) {
      num = num & (num - 1);
      count++;
    }
    return count;
  }
  vector<vector<char>> makeAllPossibleSet(vector<char> set) {
    int possibilities = 1 << set.size();
    vector<vector<char>> result;
    result.reserve(possibilities);
    for (int i = 0; i < possibilities; i++) {
      vector<char> temp;
      if (i == 0) temp.push_back('E');
      if (this->getBit(i, 0)) temp.push_back(set[0]);
      if (this->getBit(i, 1)) temp.push_back(set[1]);
      if (this->getBit(i, 2)) temp.push_back(set[2]);
      result.push_back(temp);
    }
    return result;
  }
  void findUnique(vector<int> nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      // storing all the values of xor
      result ^= nums[i];
    }
    int temp = result;
    result = 0; // reseting xor
    for (int i = 0; i < nums.size(); i++) {
      // nums[i] & temp will give us
      // where the selected position is true or not
      if (nums[i] & temp) result ^= nums[i];
    }
    cout << result << ' ' << (result ^ temp);
  }
};

int main(int argc, char const *argv[]) {
  BitManager *bit = new BitManager();
  logBit(bit->getBit(700, 1));
  logBit(bit->setBit(700, 1));
  logBit(bit->clearBit(700, 5));
  log((bit->isPowerOfTwo(65) ? "TRUE" : "FALSE"));
  logBit(40);
  log(bit->numberOfOnes(40));
  vector<char> set = {'a', 'b', 'c'};
  vector<vector<char>> result = bit->makeAllPossibleSet(set);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ' ';
    }
    cout << ", ";
  }

  cout << endl;
  vector<int> nums = {2, 4, 6, 8, 4, 5, 6, 2};
  bit->findUnique(nums);

  return 0;
}
