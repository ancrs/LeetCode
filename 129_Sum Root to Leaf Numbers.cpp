Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void cacul(TreeNode* root,int* sum,int num)
    {
        if(root->left==NULL && root->right==NULL)
        {
            (*sum)+=num+root->val;
        }
        if(root->left) cacul(root->left,sum,(num+root->val)*10);
        if(root->right) cacul(root->right,sum,(num+root->val)*10);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        if(root==NULL)
        {
            return 0;
        }
        cacul(root,&sum,0);
        return sum;
    }
};