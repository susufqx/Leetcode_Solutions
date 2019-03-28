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
        ListNode* temp = pre->next->next; // 第二个节点给temp
        pre->next->next = temp->next; // 第一个节点指向第三个节点，不再指向第二个
        temp->next = pre->next; // 第二个节点指向第一个节点，此时已经完成了交换
        pre->next = temp; // 第一个节点前的节点此刻需要指向第二个节点才对
        pre = temp->next; // 此时把第三个节点给pre，进行下一轮的操作
      }
      return dummy->next;
    }
};

// 别人的递归写法，作参考学习
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if (!head || !head->next) return head;
//         ListNode *t = head->next;
//         head->next = swapPairs(head->next->next);
//         t->next = head;
//         return t;
//     }
// };
