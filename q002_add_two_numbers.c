/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int add = 0;
    struct ListNode * head = l1;
    struct ListNode * high = (struct ListNode *)malloc(sizeof(struct ListNode));
    high->val = 1;
    high->next = NULL;

    while(l1 && l2) {
        l1->val = l1->val + l2->val + add;
        add = 0;
        if(l1->val >= 10) {
            l1->val = l1->val - 10;
            add = 1;
        }
        if (l1->next == NULL && l2->next != NULL) {
            l1->next = l2->next;
            l2->next = NULL;
        } else if(l1->next == NULL && l2->next == NULL && add == 1) {
            l1->next = high;
            add = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1) {
        l1->val = add + l1->val;
        add = 0;
        if(l1->val >= 10) {
            l1->val = l1->val -10;
            add = 1;
        }
        if(l1->next == NULL && add == 1) {
            l1->next = high;
            add = 0;
        }
        l1 = l1->next;
    }
    return head;
}
