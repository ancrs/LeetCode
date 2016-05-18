Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode* a)
{
    if(a==NULL)
    {
        return 0;
    }
    if(a->left==NULL && a->right==NULL)
    {
        return 1;
    }
    int x,y;
    x=depth(a->left);
    y=depth(a->right);
    return x > y ? x+1 : y+1;
}

bool isBalanced(struct TreeNode* root) {
    if(root== NULL)
    {
        return true;
    }
    int x,y;
    x=depth(root->left);
    y=depth(root->right);
    if(abs(x-y)>1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}