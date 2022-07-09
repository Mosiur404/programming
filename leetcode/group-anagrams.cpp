#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
  int primes[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
  int modulo = 1e9 + 7;
  unsigned long long int createHash(string s) {
    unsigned long long int key = 1;
    for (char &ch : s) {
      key *= this->primes[ch - 97];
      key %= modulo;
    }
    return key;
  }

public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<unsigned long long int, int> map;
    vector<vector<string>> result = {};
    int inputSize = strs.size();

    int index = 0;
    for (int i = 0; i < strs.size(); i++) {
      unsigned long long int currentHash = this->createHash(strs[i]);
      // insert into result
      if (map.find(currentHash) == map.end()) {
        map[currentHash] = index;
        index++;
        // enter new item
        result.push_back({strs[i]});
      } else
        // enter existing item
        result[map[currentHash]].push_back(strs[i]);
    }

    return result;
  }
};
int main(int argc, char const *argv[]) {
  vector<string> strs = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"};
  vector<vector<string>> result = Solution().groupAnagrams(strs);

  for (int i = 0; i < result.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << " ], ";
  }

  return 0;
}
