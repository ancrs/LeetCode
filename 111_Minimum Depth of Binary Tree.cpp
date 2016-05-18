Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    int x,y;
    x=minDepth(root->left);
    y=minDepth(root->right);
    if(x==0)
    {
        return y+1;
    }
    else if(y==0)
    {
        return x+1;
    }
    else
    {
       return x > y ? y+1 : x+1;
    }
}