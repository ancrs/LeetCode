Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?'




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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodestack;
        vector<int> path;
        if(root==NULL)
        {
            return path;
        }
        //nodestack.push(root);
        TreeNode* p=root;
        while(p!=NULL || !nodestack.empty())
        {
            while(p!=NULL)
            {
                nodestack.push(p);
                p=p->left;
            }
            if(!nodestack.empty())
            {
                p=nodestack.top();
                path.push_back(p->val);
                nodestack.pop();
                p=p->right;
            }
        }
        return path;
    }
};