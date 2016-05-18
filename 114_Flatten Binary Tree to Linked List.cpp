Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(root == NULL) return;
    while(root){
        if(root->left){
            struct TreeNode *pre = root->left;
            while(pre->right)
                pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}             