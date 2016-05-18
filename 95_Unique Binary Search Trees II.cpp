Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3



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
    vector<TreeNode*> create(int start,int end)
    {
        vector<TreeNode*> result;
        if(start>end)
        {
            result.push_back(NULL);
            return result;
        }
        for(int k=start;k<=end;k++)
        {
            vector<TreeNode*> left=create(start,k-1);
            vector<TreeNode*> right=create(k+1,end);
            for(int i=0;i<left.size();i++)
            {
                for(int j=0;j<right.size();j++)
                {
                    TreeNode *root=new TreeNode(k);
                    root->left=left[i];
                    root->right=right[j];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return create(1,n);
    }
};   