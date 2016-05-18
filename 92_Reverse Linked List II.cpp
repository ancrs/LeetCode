Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
        if (head == NULL)
            return NULL;
            
        struct ListNode *q = NULL;
        struct ListNode *p = head;
        for(int i = 0; i < m - 1; i++)
        {
            q = p;
            p = p->next;
        }
        
        struct ListNode *end = p;
        struct ListNode *pPre = p;
        p = p->next;
        for(int i = m + 1; i <= n; i++)
        {
            struct ListNode *pNext = p->next;
            
            p->next = pPre;
            pPre = p;
            p = pNext;
        }
        
        end->next = p;
        if (q)
            q->next = pPre;
        else
            head = pPre;
        
        return head;
}