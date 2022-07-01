#include <iostream>
#include <stack>
#include <queue>
#define log(x) std::cout << x << std::endl;
using namespace std;

struct Node {
  int val;
  Node *left, *right;
  Node() : val(0), left(nullptr), right(nullptr){};
  Node(int x) : val(x), left(nullptr), right(nullptr){};
  Node(int x, Node *left) : val(x), left(left), right(nullptr){};
  Node(int x, Node *left, Node *right) : val(x), left(left), right(right){};
};
// Function to print binary tree in 2D
// It does reverse inorder traversal
#define COUNT 4
void print2DUtil(struct Node *root, int space) {
  // Base case
  if (root == NULL) return;

  // Increase distance between levels
  space += COUNT;

  // Process right child first
  print2DUtil(root->right, space);

  // Print current struct node after space
  // count
  cout << endl;
  for (int i = COUNT; i < space; i++)
    cout << " ";
  cout << root->val << "\n";

  // Process left child
  print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node *root) {
  // Pass initial space count as 0
  print2DUtil(root, 0);
}

// start ------------------------
class BST {
private:
  struct Node *rootPtr;
  struct Node *_insert(struct Node *root, int val) {
    if (root == nullptr) return root = new struct Node(val);

    if (val <= root->val)
      root->left = this->_insert(root->left, val);
    else
      root->right = this->_insert(root->right, val);
    return root;
  }
  struct Node *_search(struct Node *root, int val) {
    if (root == nullptr) return root;
    if (val == root->val) return root;
    if (val < root->val)
      return this->_search(root->left, val);
    else
      return this->_search(root->right, val);
  }
  int _findHeight(struct Node *root) {
    if (root == nullptr) return -1;
    int leftHeight = _findHeight(root->left);
    int rightHeight = _findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
  }
  void _preOrderTraverse(struct Node *root) {
    // DLR
    if (root == nullptr) return;
    cout << root->val << ' ';
    _preOrderTraverse(root->left);
    _preOrderTraverse(root->right);
    return;
  }
  void _inOrderTraverse(struct Node *root) {
    // LDR
    if (root == nullptr) return;
    _inOrderTraverse(root->left);
    cout << root->val << ' ';
    _inOrderTraverse(root->right);
    return;
  }
  void _postOrderTraverse(struct Node *root) {
    // LDR
    if (root == nullptr) return;
    _postOrderTraverse(root->left);
    _postOrderTraverse(root->right);
    cout << root->val << ' ';
    return;
  }
  bool _isBST(struct Node *root, int min, int max) {
    if (root == nullptr) return true;
    return (root->val >= min && root->val < max &&
            this->_isBST(root->left, min, root->val) &&
            this->_isBST(root->right, root->val, max));
  }

public:
  BST *insert(int val) {
    this->rootPtr = this->_insert(this->rootPtr, val);
    return this;
  }
  bool search(int val) {
    if (this->_search(this->rootPtr, val) == nullptr) return false;
    return true;
  }

  BST *preOrderTraverse() {
    this->_preOrderTraverse(this->rootPtr);
    cout << endl;
    return this;
  }
  BST *inOrderTraverse() {
    this->_inOrderTraverse(this->rootPtr);
    cout << endl;
    return this;
  }
  BST *postOrderTraverse() {
    this->_postOrderTraverse(this->rootPtr);
    cout << endl;
    return this;
  }
  BST *levelOrderTraverse() {
    queue<struct Node *> Q;
    if (this->rootPtr == nullptr) return this;
    Q.push(rootPtr);
    while (!Q.empty() && Q.front() != nullptr) {
      struct Node *current = Q.front();
      cout << current->val << ' ';
      if (current->left != nullptr) Q.push(current->left);
      if (current->right != nullptr) Q.push(current->right);
      Q.pop();
    }
    cout << endl;
    return this;
  }
  int findHeight() { return this->_findHeight(this->rootPtr); }
  struct Node *findMin() {
    if (this->isEmpty()) return nullptr;
    struct Node *current = this->rootPtr;
    while (current->left != nullptr)
      current = current->left;
    return current;
  }
  struct Node *findMax() {
    if (this->isEmpty()) return nullptr;
    struct Node *current = this->rootPtr;
    while (current->right != nullptr)
      current = current->right;
    return current;
  }

  bool isBST() { return this->_isBST(this->rootPtr, INT_MIN, INT_MAX); }

  struct Node *findMinFromNode(struct Node *root) {
    if (root->left == nullptr) return root;
    return findMinFromNode(root->left);
  }
  struct Node *_remove(struct Node *root, int val) {
    if (root == nullptr) return root;
    if (val < root->val)
      root->left = this->_remove(root->left, val);
    else if (val > root->val)
      root->right = this->_remove(root->right, val);
    else {
      // value found
      // case 1: no child
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr; // root will be set to null;
        // case 2: 1 child
      } else if (root->left == nullptr) { // if there is a right node
        struct Node *current = root;
        root = root->right;
        delete current;
        // case 2: 1 child
      } else if (root->right == nullptr) { // if there is a left node
        struct Node *current = root;
        root = root->left;
        delete current;
      }
      // case 3: 2 child
      else {
        struct Node *min = this->findMinFromNode(root->right);
        root->val = min->val;
        root->right = this->_remove(root->right, min->val);
      }
    }
    return root;
  }
  BST *remove(int val) {
    this->rootPtr = this->_remove(this->rootPtr, val);
    return this;
  }

  struct Node *getSuccessor(int val) {
    struct Node *current = this->_search(this->rootPtr, val);
    if (current == nullptr) return nullptr;

    // Case 01: Node has a right subtree
    if (current->right != nullptr)
      return findMinFromNode(current->right);

    else {
      struct Node *ancestor = this->rootPtr;
      struct Node *successor = nullptr;

      while (ancestor != nullptr) {
        if (current->val < ancestor->val) {
          successor = ancestor;
          ancestor = ancestor->left;
        } else
          ancestor = ancestor->right;
      }
      return successor;
    }
  }
  struct Node *getPrededcessor(int val) {
    return nullptr;
  }
  /* Extra */
  bool isEmpty() { return this->rootPtr == nullptr; }
  int handleEmpty() {
    cout << "Tree is empty." << endl;
    return 0;
  }
  int max(int a, int b) { return a > b ? a : b; }
  int min(int a, int b) { return a < b ? a : b; }
  void print() {
    struct Node *temp = this->rootPtr;
    print2D(temp);
  }
  BST() { this->rootPtr = nullptr; }
};

int main(int argc, char const *argv[]) {
  BST *tree = new BST();

  tree->insert(15)->insert(10)->insert(20);
  tree->insert(8)->insert(12)->insert(17)->insert(25);
  tree->insert(6)->insert(11)->insert(16)->insert(27);

  tree->print();
  cout << (tree->search(33) ? "TRUE" : "FALSE") << endl;

  cout << "Min: " << (tree->findMin() == nullptr ? tree->findMin()->val : 0)
       << endl;
  cout << "Max: " << (tree->findMax() == nullptr ? tree->findMax()->val : 0)
       << endl;
  cout << "Height: " << tree->findHeight() << endl;
  cout << "Pre Order Traverse: ";
  tree->preOrderTraverse();
  cout << "In Order Traverse: ";
  tree->inOrderTraverse();
  cout << "Post Order Traverse: ";
  tree->postOrderTraverse();
  cout << "Level Order Traverse: ";
  tree->levelOrderTraverse();
  cout << "Is Binary Tree: " << (tree->isBST() ? "True" : "False") << endl;
  cout << "Successor: "
       << (tree->getSuccessor(12) != nullptr ? tree->getSuccessor(12)->val : 0)
       << endl;
  cout << "Delete: ";
  tree->remove(10)->print();
  return 0;
}
