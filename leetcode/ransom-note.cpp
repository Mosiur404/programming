#include <iostream>
#include <unordered_map>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int frequency[26] = {0};
    int charAscii = 97;
    for (int i = 0; i < magazine.size(); i++)
      frequency[magazine[i] - charAscii]++;

    for (int i = 0; i < ransomNote.size(); i++)
      if (--frequency[ransomNote[i] - charAscii] < 0) return false;

    return true;
  }
};
// class Solution {
//  public:
//   bool canConstruct(string ransomNote, string magazine) {
//     unordered_map<char, int> letterCountMap;

//     //    ransomNote = "aa", magazine = "aab";
//     int magazineLength = magazine.length();

//     for (int i = 0; i < magazineLength; i++) {
//       if (letterCountMap.find((magazine[i])) == letterCountMap.end())
//         letterCountMap[magazine[i]] = 1;
//       else
//         letterCountMap[magazine[i]]++;
//     }

//     int ransomLength = ransomNote.length();
//     for (int i = 0; i < ransomLength; i++) {
//       if (letterCountMap.find((ransomNote[i])) == letterCountMap.end())
//         return false;
//       else {
//         if (letterCountMap[ransomNote[i]] == 0) return false;
//         letterCountMap[ransomNote[i]]--;
//       }
//     }

//     return true;
//   }
// };

int main(int argc, char const* argv[]) {
  Solution leet;
  string ransomNote = "aab", magazine = "aba";
  bool result = leet.canConstruct(ransomNote, magazine);

  cout << (result ? "TRUE" : "FALSE") << endl;
  return 0;
}
