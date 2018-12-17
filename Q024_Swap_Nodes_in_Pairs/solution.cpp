/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      ListNode* dummy = new ListNode(-1);
      ListNode* pre = dummy;
      dummy->next = head; //此处就是获取head的地址保存在dummy->next里, 这也保证了pre指向与dummy指向都是head了
      while (pre->next && pre->next->next) {
        ListNode* temp = pre->next->next;
        pre->next->next = temp->next;
        temp->next = pre->next;
        pre->next = temp;
        pre = temp->next;
      }
      return dummy->next;
    }
};
