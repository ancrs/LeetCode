Given an array where elements are sorted in ascending order, convert it to a height balanced BST.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* create(int* nums,int left,int right)
{
    if(left>right)
    {
        return NULL;
    }
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid=left+(right-left)/2;
    root->val=nums[mid];
    root->left=create(nums,left,mid-1);
    root->right=create(nums,mid+1,right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return create(nums,0,numsSize-1);
}