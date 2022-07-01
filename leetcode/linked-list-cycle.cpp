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
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    ListNode *turtle = head;
    ListNode *hare = head->next;
    int power = 1;
    int length = 1;

    while (turtle != hare && hare != nullptr) {
      if (power == length) {
        power = power << 1;
        length = 0;
        turtle = hare;
      }
      hare = hare->next;
      length++;
    }
    if (hare == nullptr) return false;
    return true;
  }
};
// class Solution {
// public:
//   bool hasCycle(ListNode *head) {
//     ListNode *slow = head;
//     ListNode *fast = head;
//     while (fast != nullptr && fast->next != nullptr) {
//       slow = slow->next;
//       fast = fast->next->next;
//       if (slow == fast) return true;
//     }
//     return false;
//   }
// };
// class Solution {
// public:
//   bool hasCycle(ListNode *head) {
//     ListNode *current = head;
//     unordered_map<uintptr_t, bool> map;
//     while (current != nullptr) {
//       // ! found
//       if (map.find((uintptr_t)current) == map.end())
//         map[(uintptr_t)current] = true;
//       else
//         return true;
//       current = current->next;
//     }
//     return false;
//   }
// };

int main(int argc, char const *argv[]) {
  ListNode *head1 = new ListNode();
  int list1[] = {3, 2, 0, -4};

  ListNode *current1 = head1;
  ListNode *loopNode = head1;

  for (int i = 0; i < 4; i++) {
    current1->next = new ListNode(list1[i]);
    // if (i == 1) loopNode = current1->next;
    current1 = current1->next;
  }
  // cout << loopNode->val << ' ' << current1->val;
  current1->next = loopNode;

  Solution leet;
  bool result = leet.hasCycle(head1->next);

  cout << (result ? "TRUE" : "FALSE") << endl;
  return 0;
}
