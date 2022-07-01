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
  ListNode *
  reverseList(ListNode *head) { // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null
    // when it hits the last node
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *next = this->reverseList(head->next);
    // head = 6, next = 7
    ListNode *current = head->next; // current = 7
    current->next = head;           // 7 -> 6
    head->next = nullptr;           // 6 -> nullptr
    cout << head->val << ' ' << next->val << endl;
    return next; // next is 6
  }
};
// class Solution {
// public:
//   ListNode *reverseList(ListNode *head) {
//     ListNode *current = head;
//     ListNode *next = nullptr, *prev = nullptr;

//     while (current != nullptr) {
//       next = current->next; // saving it for later use

//       // the one we get from prev iteration
//       // initially it will be nullptr
//       // so end will be nullptr
//       current->next = prev;

//       prev = current; // will be used on next iteration

//       current = next; // moving to next iteration
//     }
//     return prev;
//   }
// };

int main(int argc, char const *argv[]) {
  ListNode *head = new ListNode();
  int list[] = {1, 2, 3, 4, 5, 6, 7};

  ListNode *current = head;

  for (int i = 0; i < 7; i++) {
    current->next = new ListNode(list[i]);
    current = current->next;
  }

  Solution leet;
  ListNode *result = leet.reverseList(head->next);

  ListNode *temp = result;
  while (temp != nullptr) {
    cout << temp->val << ' ';
    temp = temp->next;
  }
  return 0;
}
