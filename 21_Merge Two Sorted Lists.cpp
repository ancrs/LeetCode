Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p,*q,*head,*a;
    if(l1==NULL && l2==NULL)
    {
        return NULL;
    }
    if(l1==NULL && l2!=NULL)
    {
        return l2;
    }
    if(l1!=NULL && l2==NULL)
    {
        return l1;
    }
    p=l1;
    q=l2;
    a=head;
    while(p!=NULL && q!=NULL)
    {
        if(p->val<=q->val)
        {
            head->next=p;
            head=head->next;
            p=p->next;
        }
        else
        {
            head->next=q;
            head=head->next;
            q=q->next;
        }
    }
    if(p==NULL && q==NULL)
    {
        head->next=NULL;
    }
    if(p!=NULL)
    {
        head->next=p;
    }
    if(q!=NULL)
    {
        head->next=q;
    }
    return a->next;
}