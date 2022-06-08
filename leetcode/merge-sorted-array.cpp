#include <iostream>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    if (n == 0) return;

    int k = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0) {
      if (nums1[i] < nums2[j]) {
        nums1[k] = nums2[j];
        k--;
        j--;
      } else {
        nums1[k] = nums1[i];
        k--;
        i--;
      }
    }
    while (j >= 0) nums1[k--] = nums2[j--];
  }
};

int main(int argc, char const* argv[]) {
  Solution leet;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  leet.merge(nums1, 3, nums2, 3);
  vector<int> result = nums1;
  for (int i = 0; i < (int)result.size(); i++) cout << result[i] << ' ';
  return 0;
}