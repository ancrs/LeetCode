Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
dummy->val=INT_MAX;
dummy->next=head;
struct ListNode* prev=dummy; 
struct ListNode* Next=NULL;    
struct ListNode* curr=dummy->next;    

while(curr){
    Next=curr->next;

    if(curr->val==val){
        prev->next=curr->next;
        free(curr);
    }
    else
        prev=curr;

    curr=Next;  
}

return dummy->next;
}