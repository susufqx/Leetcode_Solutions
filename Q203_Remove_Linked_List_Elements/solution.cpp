#include <iostream>

using namespace std;

struct ListNode {
   int val;
   ListNode * next;
   ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode * removeElements(ListNode* head, int val) {
      if (head == NULL) {
        return head;
      }
      ListNode * l1;
      ListNode * l2;
      l1 = head;

      while(l1 != NULL) {
        while(l1->val != val && l1->next != NULL) {
          l2 = l1;
          l1 = l1->next;
        }
        if (l1->val == val) {
          if (head->val == val) {
            head = head->next;
          } else {
            l2->next = l1->next;
          }
        }
        l1 = l1->next;
      }
      return head;
    }

    ListNode * create_list(int n, int * array) {
      int i;
      ListNode * l = (ListNode *)malloc(sizeof(ListNode));
      ListNode * head = l;
      ListNode * temp = l;
      for (i = 0; i < n; i++) {
        temp->val = array[i]; // or temp->val, now temp equals l
        if (i == n-1) {
          temp->next = NULL;
        } else {
          l = (ListNode *)malloc(sizeof(ListNode)); // create the new address
          temp->next = l;
          temp = l;
        }
      }
      return head;
    }

    void print_list(ListNode * li) {
      int i = 0;
      while(li) {
        if (i % 10 == 9 && li->next != NULL) {
          printf("\n");
        }
        printf("%d", li->val);
        if (li->next != NULL) {
          printf("-->");
        }
        i += 1;
        li = li->next;
      }
      printf("\n");
    }
};

int main(int argc, char ** argv) {
  int * array;
  int i, num;
  Solution solu;

  cout<<"Please enter the number of array:"<<endl;
  cin>>num;

  array = new int[num];

  for (i = 0; i < num; i++) {
    array[i] = rand() % 90 + 10;
  }

  ListNode * list = solu.create_list(num, array);
  solu.print_list(list);
  ListNode * t = solu.removeElements(list, 33);
  solu.print_list(t);
  return 0;
}
