#include <iostream>
#include <cstdint>
#include <unordered_map>
#define log(x) std::cout << x << std ::endl;
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    ListNode *next = node->next;
    node->val = next->val;
    node->next = next->next;
    delete next;
  }
};

int main(int argc, char const *argv[]) {
  ListNode *head = new ListNode();
  int list[] = {1, 2, 3, 4, 5, 6, 7};

  ListNode *current = head;
  ListNode *deleteN;

  for (int i = 0; i < 7; i++) {
    current->next = new ListNode(list[i]);
    if (i == 4) deleteN = current->next;
    current = current->next;
  }

  Solution leet;
  leet.deleteNode(deleteN);

  ListNode *temp = head->next;
  while (temp != nullptr) {
    cout << temp->val << ' ';
    temp = temp->next;
  }
  return 0;
}
