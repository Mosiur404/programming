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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // if both null mean both is leaf
    if (p == nullptr && q == nullptr) return true;
    // if one is null and other is not then tree structure not same
    if (p == nullptr || q == nullptr) return false;
    // if value same then go till then do the same till the end of tree
    if (p->val == q->val)
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    else
      return false;
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *tree1 = new TreeNode(1), *tree2 = new TreeNode(1);

  tree1->left = new TreeNode(2), tree2->left = new TreeNode(2);
  tree1->right = new TreeNode(3), tree2->right = new TreeNode(3);

  bool result = Solution().isSameTree(tree1, tree2);

  cout << (result ? "TRUE" : "FALSE") << endl;

  return 0;
}
