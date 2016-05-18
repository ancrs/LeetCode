You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    if(l1 == NULL)
    {
        return l2;
    }

    if(l2 == NULL)
    {
        return l1;
    }

    struct ListNode *pre, *head=l1;
    int tmp = 0;
    while(l1 != NULL && l2 != NULL)
    {
        l1->val +=  (l2->val + tmp);
        if(l1->val >= 10)
        {
            l1->val -= 10;
            tmp = 1;
        }
        else
        {
            tmp = 0;
        }

        pre = l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    struct ListNode *next= l1 != NULL? l1: l2;
    pre->next = next;
    while(next !=NULL && tmp != 0)
    {
        next->val +=  tmp;
        if(next->val >= 10)
        {
            next->val -= 10;
            tmp = 1;
        }
        else
        {
            tmp = 0;
        }
        pre = next;
        next = next->next;
    }

    if(tmp)
    {
        struct ListNode *tmpNode = malloc(sizeof(struct ListNode));
        tmpNode->next = NULL;
        tmpNode->val = 1;
        pre->next = tmpNode;
    }
    return head;
}