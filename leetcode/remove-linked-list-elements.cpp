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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *newHead = new ListNode();
    newHead->next = head;

    ListNode *prev = newHead;
    ListNode *current = head;

    while (current != nullptr) {
      if (current->val == val) {
        prev->next = current->next;
        delete current;
        current = prev->next;
        continue;
      }

      prev = current;
      current = current->next;
    }
    current = newHead->next;
    delete newHead;
    return current;
  }
};

int main(int argc, char const *argv[]) {
  ListNode *head = new ListNode();
  int list[] = {6, 2, 6, 3, 4, 5, 6};

  ListNode *current = head;

  for (int i = 0; i < 7; i++) {
    current->next = new ListNode(list[i]);
    current = current->next;
  }

  Solution leet;
  ListNode *result = leet.removeElements(new ListNode(1), 6);
  cout << "result: " << result << endl;
  ListNode *temp = result;
  while (temp != nullptr) {
    cout << temp->val << ' ';
    temp = temp->next;
  }
  return 0;
}
