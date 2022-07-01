#include <iostream>
#include <cstdint>
#include <unordered_map>
#define log(x) std::cout << x << std ::endl;
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;

    while (temp1 != temp2) {
      temp1 = temp1 ? temp1->next : headA;
      temp2 = temp2 ? temp2->next : headB;
    }
    return temp1;
  }
};
// class Solution {
// public:
//   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     unordered_map<uintptr_t, bool> hashMap;
//     ListNode *temp1 = headA;
//     ListNode *temp2 = headB;

//     while (temp1 != nullptr || temp2 != nullptr) {
//       if (temp1 == temp2) return temp1;

//       if (hashMap.find((uintptr_t)temp1) != hashMap.end()) return temp1;
//       if (hashMap.find((uintptr_t)temp2) != hashMap.end()) return temp2;

//       if (temp1 != nullptr) {
//         hashMap[(uintptr_t)temp1] = true;
//         temp1 = temp1->next;
//       }
//       if (temp2 != nullptr) {
//         hashMap[(uintptr_t)temp2] = true;
//         temp2 = temp2->next;
//       }
//     }
//     return nullptr;
//   }
// };

int main(int argc, char const *argv[]) {
  // ListNode *head1 = new ListNode(1);
  // head1->next = new ListNode(9);
  // head1->next->next = new ListNode(1);

  // ListNode *head2 = new ListNode(3);

  // ListNode *intersection = new ListNode(2);
  // intersection->next = new ListNode(4);

  // head1->next->next->next = intersection;
  // head2->next = intersection;
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(2);
  head1->next->next = new ListNode(3);
  head1->next->next->next = new ListNode(4);

  ListNode *head2 = new ListNode(5);
  head2->next = new ListNode(6);

  Solution leet;
  ListNode *result = leet.getIntersectionNode(head1, head2);

  ListNode *temp = head1;
  while (temp != nullptr) {
    cout << temp->val << ' ';
    temp = temp->next;
  }
  cout << endl;
  temp = head2;
  while (temp != nullptr) {
    cout << temp->val << ' ';
    temp = temp->next;
  }
  cout << endl;
  temp = result;
  while (temp != nullptr) {
    cout << temp->val << ' ';
    temp = temp->next;
  }
  return 0;
}
