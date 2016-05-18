Given inorder and postorder traversal of a tree, construct the binary tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize==0 || postorderSize==0)
    {
        return NULL;
    }
    struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=postorder[postorderSize-1];
    root->left=NULL;
    root->right=NULL;
    int i;
    for(i=0;i<inorderSize;i++)
    {
        if(postorder[postorderSize-1]==inorder[i])
        {
            break;
        }
    }
    root->left=buildTree(inorder,i,postorder,i);
    root->right=buildTree(inorder+i+1,inorderSize-i-1,postorder+i,postorderSize-i-1);
    return root;
}