Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* links[2000];
    struct ListNode* p;
    p=head;
    int sum=0;
    while(p!=NULL)
    {
        links[sum]=p;
        sum++;
        p=p->next;
    }
    if(sum==1 && n==1)
    {
        return NULL;
    }
    if(sum==n)
    {
        return head->next;
    }
    links[sum-n-1]->next=links[sum-n]->next;
    free(links[sum-n]);
    return head;
}