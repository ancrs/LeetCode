Sort a linked list using insertion sort.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    struct ListNode *helper=(struct ListNode*)malloc(sizeof(struct ListNOde*));
    helper->next=NULL;
    //helper->next=NULL;
    struct ListNode *pre;
    struct ListNode *cur=head;
    while(cur!=NULL)
    {
        struct ListNode* next=cur->next;
        pre=helper;
        while(pre->next!=NULL && pre->next->val<cur->val)
        {
            pre=pre->next;
        }
        cur->next=pre->next;
        pre->next=cur;
        cur=next;
    }
    return helper->next;
}