Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next = head;
        struct ListNode *cur = p, *pre = head;
        while(pre != NULL){
            bool isDupli = false;
            while(pre->next != NULL && pre->val == pre->next->val){
                isDupli = true;
                pre = pre->next;
            }
            if(isDupli){
                pre = pre->next;
                continue;
             
            }
            cur->next = pre;
            cur = cur->next;
            pre = pre->next;
            
        }
        cur->next = pre;
        return p->next;
}