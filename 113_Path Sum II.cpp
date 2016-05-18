Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void sum2(TreeNode* root,int target,vector<int> &path,vector<vector<int>> &result)
    {
        if(root==NULL)
        {
            return;
        }
        path.push_back(root->val);
        if(root->val==target && root->left==NULL && root->right==NULL)
        {
            //path.push_back(root->val);
            result.push_back(path);
            //return;
        }
        
        sum2(root->left,target-root->val,path,result);
        sum2(root->right,target-root->val,path,result);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        sum2(root,sum,path,result);
        return result;
    }
};