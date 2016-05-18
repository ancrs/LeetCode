Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
'


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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> path;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty())
        {
            if(root!=NULL)
            {
                while(root)
                {
                    path.push_back(root->val);
                    st.push(root);
                    root=root->left;
                }
            }
            else{
                root=st.top()->right;
                st.pop();
            }
        }
        return path;
    }
};