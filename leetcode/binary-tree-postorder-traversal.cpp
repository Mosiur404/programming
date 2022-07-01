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
  void _postorderTraversal(TreeNode *root, vector<int> &values) {
    if (root == nullptr) return;

    _postorderTraversal(root->left, values);
    _postorderTraversal(root->right, values);
    values.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> values = {};
    this->_postorderTraversal(root, values);
    return values;
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *tree = new TreeNode(1);

  tree->right = new TreeNode(2);
  tree->right->left = new TreeNode(3);

  vector<int> values = Solution().postorderTraversal(tree);

  for (int i = 0; i < values.size(); i++)
    cout << values[i] << ' ';

  return 0;
}
