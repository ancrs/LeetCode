Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode* root,long long leftval,long long rightval)
{
    if(root==NULL)
    {
        return true;
    }
    return root->val<rightval & root->val>leftval & check(root->left,leftval,root->val) & check(root->right,root->val,rightval);
}
bool isValidBST(struct TreeNode* root) {
    return check(root,INT64_MIN,INT64_MAX);
}