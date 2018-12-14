# include <iostream>
# include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(!head->next) return NULL; // 空链表
      ListNode * left = head, * right = head;
      for(int i=0;i<n;i++){
        right = right->next;
      }
      if(!right) return head->next;
      while(right->next){
        left = left->next;
        right = right->next;
      }
      left->next = left->next->next;
      return head;
    }
};

int main(int argc, char ** argv){

  return 0;
}
