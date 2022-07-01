#include <iostream>
#include <cmath>
#include <queue>
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
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr)
      return root->val == targetSum;

    targetSum -= root->val;
    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);

  root->left->left = new TreeNode(11);
  //   root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);

  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);

  root->right->right->right = new TreeNode(1);

  bool result = Solution().hasPathSum(root, 22);

  cout << (result ? "TRUE" : "FALSE") << endl;

  return 0;
}
