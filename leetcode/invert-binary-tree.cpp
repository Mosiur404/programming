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
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return nullptr;

    TreeNode *left = root->left, *right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);

    return root;
  }
};
int main(int argc, char const *argv[]) {
  TreeNode *tree = new TreeNode(1);

  tree->left = new TreeNode(2);
  tree->right = new TreeNode(7);

  tree->left->left = new TreeNode(1);
  tree->left->right = new TreeNode(3);

  tree->right->left = new TreeNode(6);
  tree->right->right = new TreeNode(9);

  TreeNode *values = Solution().invertTree(tree);

  return 0;
}
