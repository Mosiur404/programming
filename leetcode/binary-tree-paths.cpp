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
  void _inorderTraversal(TreeNode *root, vector<string> &values, string s) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
      values.push_back(s + to_string(root->val));
      return;
    }
    s += to_string(root->val) + "->";
    _inorderTraversal(root->left, values, s);
    _inorderTraversal(root->right, values, s);
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> values = {};
    this->_inorderTraversal(root, values, "");
    return values;
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *tree = new TreeNode(1);

  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);

  tree->left->right = new TreeNode(5);

  vector<string> values = Solution().binaryTreePaths(tree);

  for (int i = 0; i < values.size(); i++) {
    cout << values[i] << ' ';
  }

  return 0;
}
