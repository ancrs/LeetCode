Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(0 == k || NULL == head)
			return head;
        int listSize = 1;
		struct ListNode* tail = head;
		struct ListNode* ret = head;
		while(tail->next != NULL)
		{
			tail = tail->next;
			++listSize;
		}
		k %= listSize;
		if(k > 0)
		{
			struct ListNode* cur = head;
			for(int i = 1; i < listSize - k; ++i)
				cur = cur->next;
			ret = cur->next;
			tail->next = head;
			cur->next = NULL;
		}
		return ret;
}