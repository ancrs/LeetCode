Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
'



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//利用快慢指针将链表切成两段，将第二段翻转
void reorderList(struct ListNode* head) {
    struct ListNode *slow,*fast,*cur;
    slow=head;
    fast=head;
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cur=slow->next;
    slow->next=NULL;
    struct ListNode *p=NULL;
    while (cur) 
    {
        struct ListNode *temp = cur;
        cur = cur->next;
        temp->next = p;
        p =  temp;
    }
    struct ListNode* node1=head;
    while(p!=NULL)
    {
        struct ListNode* tmp1=node1->next;
        struct ListNode* tmp2=p->next;
        node1->next=p;
        p->next=tmp1;
        node1=tmp1;
        p=tmp2;
    }
}