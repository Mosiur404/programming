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
  bool _isSymmetric(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;

    if (root1->val == root2->val)
      return this->_isSymmetric(root1->left, root2->right) &&
             this->_isSymmetric(root1->right, root2->left);
    else
      return false;
  }
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return this->_isSymmetric(root->left, root->right);
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *tree = new TreeNode(1);

  tree->left = new TreeNode(2);
  tree->right = new TreeNode(2);

  tree->left->left = new TreeNode(3);
  tree->left->right = new TreeNode(4);

  tree->right->right = new TreeNode(3);
  tree->right->left = new TreeNode(4);

  bool result = Solution().isSymmetric(tree);

  cout << (result ? "TRUE" : "FALSE") << endl;

  return 0;
}
