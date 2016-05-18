Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow,*fast;
    slow=head;
    fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}