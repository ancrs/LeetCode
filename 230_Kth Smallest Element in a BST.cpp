Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
'


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int caculate(struct TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+caculate(root->left)+caculate(root->right);
}
int kthSmallest(struct TreeNode* root, int k) {
    if(root==NULL)
    {
        return 0;
    }
    int left=caculate(root->left);
    if(k==left+1)
    {
        return root->val;
    }
    else if(k>left+1)
    {
        return kthSmallest(root->right,k-left-1);
    }
    else{
        return kthSmallest(root->left,k);
    }
}