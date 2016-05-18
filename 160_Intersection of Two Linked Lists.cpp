Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int i, len, len1 = 0, len2 = 0;
struct ListNode *temp1 = NULL;
struct ListNode *temp2 = NULL;
struct ListNode *headC = (struct ListNode *)malloc(sizeof(struct ListNode));

for(temp1 = headA; temp1 != NULL; temp1 = temp1->next)
{
    len1++;
}
for(temp2 = headB; temp2 != NULL; temp2 = temp2->next)
{
    len2++;
}

if(len2 > len1)
{
    len = len2 - len1;
    temp1 = headB;
    temp2 = headA;
}
else
{
    len = len1 - len2;
    temp1 = headA;
    temp2 = headB;
}

for(i = 0; i < len; i++)
{
    temp1 = temp1->next;
}
while(temp1 != NULL)
{
    if(temp1 == temp2)
    {
        headC = temp1;
        return headC;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
}
return NULL;
}