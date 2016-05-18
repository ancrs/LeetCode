Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool duichen(struct TreeNode* a,struct TreeNode* b)
{
    if(a==NULL && b==NULL)
    {
        return true;
    }
    return (a && b && a->val==b->val) && duichen(a->left,b->right) && duichen(a->right,b->left);
}

bool isSymmetric(struct TreeNode* root) {
    return root==NULL || duichen(root->left,root->right);
}