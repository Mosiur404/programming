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
  bool check(const string str) {
    int start = 0, end = str.size() - 1;

    if (end < 1) return true;
    while (start < end) {
      if (str[start] != str[end]) return false;

      start++;
      end--;
    }
    return true;
  }
  bool isPalindrome(ListNode* head) {
    string str = "";
    ListNode* temp = head;
    while (temp != nullptr) {
      str += (temp->val);
      temp = temp->next;
    }
    return this->check(str);
  }
};

int main(int argc, char const* argv[]) {
  ListNode* head1 = new ListNode();
  int list1[] = {1, 2};

  ListNode* current1 = head1;
  for (int i = 0; i < 2; i++) {
    current1->next = new ListNode(list1[i]);
    current1 = current1->next;
  }

  Solution leet;
  bool result = leet.isPalindrome(head1->next);

  cout << (result ? "TRUE" : "FALSE") << endl;
  return 0;
}
