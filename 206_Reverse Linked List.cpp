Reverse a singly linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode *current = head;
    struct ListNode *tail = NULL;
    while (current) {
        struct ListNode *temp = current;
        current = current->next;
        temp->next = tail;
        tail =  temp;
    }
    return tail;
}