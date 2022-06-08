#include <iostream>
#define log(x) std::cout << x << std ::endl;
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
      ListNode* next = current->next;
      if (next != nullptr && current->val == next->val) {
        current->next = next->next;
        delete next;
      } else
        current = current->next;
    }
    return head;
  }
};

int main(int argc, char const* argv[]) {
  ListNode* head = new ListNode();
  int list[] = {1, 2, 2};

  ListNode* current = head;
  for (int i = 0; i < 3; i++) {
    current->next = new ListNode(list[i]);
    current = current->next;
  }
  Solution leet;
  ListNode* result = leet.deleteDuplicates(head->next);

  log("result:");
  while (result != nullptr) {
    cout << result->val << ' ';
    result = result->next;
  }

  return 0;
}
