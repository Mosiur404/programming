#include <iostream>
#include <cmath>
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
  int _isBalanced(TreeNode *root) {
    if (root == nullptr) return 0;
    int leftHeight = this->_isBalanced(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = this->_isBalanced(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
  }
  bool isBalanced(TreeNode *root) { return (this->_isBalanced(root) != -1); }
};

int main(int argc, char const *argv[]) {
  TreeNode *tree = new TreeNode(1);

  tree->left = new TreeNode(2);
  tree->right = new TreeNode(2);

  //   tree->left->left = new TreeNode(3);
  //   tree->left->right = new TreeNode(3);

  //   tree->left->left->left = new TreeNode(4);
  //   tree->left->left->right = new TreeNode(4);

  bool result = Solution().isBalanced(tree);

  cout << (result ? "TRUE" : "FALSE") << endl;

  return 0;
}
