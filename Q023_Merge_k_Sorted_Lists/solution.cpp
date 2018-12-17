/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.empty()) return NULL;
      if(lists.size() == 1) return lists[0];
      ListNode* res;
      res = lists[0];
      for (int i=1;i<lists.size();i++) {
        res = this->mergeTwoLists(res, lists[i]);
      }
      return res;
    }

private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
      ListNode * output = new ListNode(0); // 由于开始不知道output是接a还是b，所以我们先创立一个指向NULL的列表
      ListNode * h = output; //这个用来处理链接关系
      while(a && b) {
        if (a->val < b->val) {
          h->next = a; // 自然指向a
          a = a->next; // a需要使用下一个node
        } else{ // 反之
          h->next = b;
          b = b->next;
        }
        h = h->next;
      }
      h->next = a?a:b;
      return output->next;
    }
};
