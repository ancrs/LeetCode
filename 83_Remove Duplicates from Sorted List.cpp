Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL)
    {
        return NULL;
    }
    struct ListNode* p,q;
    p=head;
    while(p!=NULL)
    {
        if(p->next!=NULL)
        {
            if(p->val == p->next->val)
            {
                p->next=p->next->next;
                continue;
            }
        }
        p=p->next;
    }
    return head;
}