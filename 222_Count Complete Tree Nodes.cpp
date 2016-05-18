Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 

It can have between 1 and 2h nodes inclusive at the last level h.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (NULL == root)
        {
            return 0;
        }

        int leftHeight = 1;
        int rightHeight = 1;
        struct TreeNode *p = root->left;
        while (p != NULL)
        {
            leftHeight++;
            p = p->left;
        }
    
        p = root->right;
        while (p != NULL)
        {
            rightHeight++;
            p = p->right;
        }

        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) - 1;
        }

        return countNodes(root->left) + countNodes(root->right)+1;
}