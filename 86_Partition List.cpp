Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *p,*q;
    struct ListNode *head1,*head2;
    struct ListNode *h1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *h2=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=head;
    h1->next=NULL;
    h2->next=NULL;
    head1=h1;
    head2=h2;
    while(p!=NULL)
    {
        if(p->val<x)
        {
            h1->next=p;
            h1=h1->next;
            
        }
        else
        {
            h2->next=p;
            h2=h2->next;
        }
        p=p->next;
    }
    h1->next=head2->next;
    h2->next=NULL;
    return head1->next;
}