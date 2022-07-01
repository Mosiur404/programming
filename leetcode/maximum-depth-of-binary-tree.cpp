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
  int max(int a, int b) { return a > b ? a : b; }
  int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    return this->max(this->maxDepth(root->left), this->maxDepth(root->right)) +
           1;
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *tree = new TreeNode(3);

  tree->left = new TreeNode(9);
  tree->right = new TreeNode(20);

  tree->right->left = new TreeNode(15);
  tree->right->right = new TreeNode(7);
  tree->right->right->left = new TreeNode(7);

  int result = Solution().maxDepth(tree);

  cout << "Result: " << result << endl;

  return 0;
}
