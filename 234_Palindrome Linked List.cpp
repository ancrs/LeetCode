Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverselist(struct ListNode* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    struct ListNode *cur,*p;
    cur=head;
    struct ListNode* h=(struct ListNode*)malloc(sizeof(struct ListNode));
    h->next=NULL;
    while(cur!=NULL)
    {
        struct ListNode* tmp=cur->next;
        cur->next=h->next;
        h->next=cur;
        cur=tmp;
    }
    return h->next;
}
//利用快慢指针截成两端，翻转前面的，比较这两段 
bool isPalindrome(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
    {
        return true;
    }
    struct ListNode *slow,*fast;
    slow=head;
    fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast!=NULL)
    {
        slow->next=reverselist(slow->next);
        slow=slow->next;
    }
    else
    {
        slow=reverselist(slow);
    }
    fast=head;
    while(slow!=NULL)
    {
        if(slow->val!=fast->val)
        {
            return false;
        }
        slow=slow->next;
        fast=fast->next;
    }
    return true;
}