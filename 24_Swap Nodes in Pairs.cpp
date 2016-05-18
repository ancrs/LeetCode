Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *tmp,*flag,*t;
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    flag=head;
    struct ListNode* pre=(struct listNode*)malloc(sizeof(struct ListNode));
    pre->next=NULL;
    t=pre;
    while(flag!=NULL && flag->next!=NULL)
    {
        tmp=flag->next->next;
        pre->next=flag->next;
        pre->next->next=flag;
        flag->next=tmp;
        pre=flag;
        flag=tmp;
        
    }
    return t->next;
}