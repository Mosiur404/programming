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
  int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    queue<pair<TreeNode *, int>> Q;
    Q.push({root, 1});
    while (!Q.empty()) {
      pair<TreeNode *, int> current = Q.front();

      if (current.first->left == nullptr && current.first->right == nullptr)
        return current.second;
      if (current.first->left != nullptr)
        Q.push({current.first->left, current.second + 1});
      if (current.first->right != nullptr)
        Q.push({current.first->right, current.second + 1});
      Q.pop();
    }
    return 0;
  }
};
// class Solution {
// public:
//   int minDepth(TreeNode *root) {
//     if (root == nullptr) return 0;
//     if (root->left == nullptr && root->right == nullptr) return 1;
//     if (root->left == nullptr) return minDepth(root->right) + 1;
//     if (root->right == nullptr) return minDepth(root->left) + 1;

//     return min(minDepth(root->left), minDepth(root->right)) + 1;
//   }
// };

int main(int argc, char const *argv[]) {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);

  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);

  int result = Solution().minDepth(root);

  cout << "RESULT: " << (result) << endl;

  return 0;
}
