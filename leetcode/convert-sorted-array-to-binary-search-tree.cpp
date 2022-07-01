#include <iostream>
#include <algorithm>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  struct TreeNode *bst(int left, int right, vector<int> &nums) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    struct TreeNode *root = new TreeNode(nums[mid]);
    root->left = bst(left, mid - 1, nums);
    root->right = bst(mid + 1, right, nums);
    return root;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    return this->bst(left, right, nums);
  };
};

struct TreeNode *printBST(struct TreeNode *root) {
  if (root == nullptr) return nullptr;

  root->left = printBST(root->left);
  cout << root->val << ' ';
  root->right = printBST(root->right);

  return root;
}

int main(int argc, char const *argv[]) {
  vector<int> tree = {-10, -3, 0, 5, 9};
  TreeNode *result = Solution().sortedArrayToBST(tree);

  printBST(result);

  return 0;
}
