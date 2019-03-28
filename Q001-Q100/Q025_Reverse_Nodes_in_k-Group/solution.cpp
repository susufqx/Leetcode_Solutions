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
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (!head || k == 1) return head; // 两种特殊情况，第一个是head为NULL，另一种是k为1那就不需要变化
      ListNode* dumpy = new ListNode(0);
      ListNode* pre = dumpy;
      ListNode* cur = head;
      dumpy->next = head;
      int i = 0;
      while (cur) {
        i++;
        if (i % k == 0) {
          pre = reverseOneGroup(pre, cur->next);
          cur = pre->next;
        } else {
          cur = cur->next;
        }
      }
      return dumpy->next;
    }

    ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
      ListNode* last = pre->next;
      ListNode* cur = last->next;
      while (cur != next) {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
      }
      return last; // 此处返回的就是反转完成之后，最后一个节点
    }
};
