# include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode * output = new ListNode(0); // 由于开始不知道output是接l1还是l2，所以我们先创立一个指向NULL的列表
      ListNode * h = output; //这个用来处理链接关系
      while(l1 && l2){
        if(l1->val < l2->val){
          h->next = l1; // 自然指向l1
          l1 = l1->next; // l1需要使用下一个node
        }else{ // 反之
          h->next = l2;
          l2 = l2->next;
        }
        h = h->next;
      }
      h->next = l1?l1:l2;
      return output->next;
    }
};

int main(int argc, char ** argv){
  /*
    test code here
   */
  return 0;
}
