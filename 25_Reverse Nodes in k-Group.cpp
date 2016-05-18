Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *current, *previous, *scout;
    int count;

    scout = current = head;
    previous = NULL;
    count = 0;

    while (scout) {

        ++count;

        if (k > 1 && count == k) {

            scout = scout->next;
            struct ListNode *first, *following;
            first = current;

            while (count-- > 1) {

                following = current->next;
                current->next = following->next;
                following->next = first;
                first = following;
            }

            if (previous)
                previous->next = first;
            else
                head = first;

            previous = current;
            current = scout;
            count = 0;
        }
        else
            scout = scout->next;
    }

    return head;
}