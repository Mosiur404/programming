#include <iostream>
#define log(x) std::cout << x << std ::endl;
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* current1 = list1;
    ListNode* current2 = list2;
    ListNode* HeadPtr = new ListNode();
    ListNode* result = HeadPtr;

    while (current1 != nullptr && current2 != nullptr) {
      ListNode* next1 = current1->next;
      ListNode* next2 = current2->next;

      if (current1->val < current2->val) {
        result->next = current1;
        result = result->next;
        current1 = next1;
      } else if (current1->val > current2->val) {
        result->next = current2;
        result = result->next;
        current2 = next2;
      } else {
        result->next = current1;
        result = result->next;
        result->next = current2;
        result = result->next;
        current1 = next1;
        current2 = next2;
      }
    }

    if (current1 != nullptr) result->next = current1;
    if (current2 != nullptr) result->next = current2;
    result = HeadPtr->next;
    delete HeadPtr;
    return result;
  }
};

int main(int argc, char const* argv[]) {
  ListNode* head1 = new ListNode();
  ListNode* head2 = new ListNode();
  int list1[] = {1, 2, 4};
  int list2[] = {1, 3, 4};

  ListNode* current1 = head1;
  ListNode* current2 = head2;
  for (int i = 0; i < 3; i++) {
    current1->next = new ListNode(list1[i]);
    current1 = current1->next;

    current2->next = new ListNode(list2[i]);
    current2 = current2->next;
  }
  Solution leet;
  ListNode* result = leet.mergeTwoLists(head1->next, head2->next);

  log("result:");
  while (result != nullptr) {
    log(result->val);
    result = result->next;
  }

  return 0;
}
