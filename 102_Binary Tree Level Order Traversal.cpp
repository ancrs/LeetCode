Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]'


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(returnSize == NULL)
    return NULL;
if(root == NULL){
    *returnSize = 0;
    return NULL;
}
*columnSizes = (int *)malloc(sizeof(int) * 1000);
memset(*columnSizes,0,sizeof(*columnSizes));
struct TreeNode *queue[2000], *temp;
int first = 0, end = 0;
int **result = (int **)malloc(sizeof(int *) * 1000);
int i = 1, j = 0, k = 0, m = 0, n = 0;
/* root enter queue */
queue[end++] = root;
while(end > first)
{
    result[k] = (int *)malloc(sizeof(int) * 1000);
    m = 0;
    /* use i to control the number of elements in each level */
    for(j = 0; j < i && end > first; j++){
        /* out the front */
        temp = queue[first++];
        result[k][m++] = temp -> val;
        /* lchild and rchild enter the queue */
        if(temp -> left){
            queue[end++] = temp -> left;
            n++;
        }
        if(temp -> right){
            queue[end++] = temp -> right;
            n++;
        }
    }
    (*columnSizes)[k++] = m;
    if(!(i = n))
        break;
    n = 0;
}
*returnSize = k;
return result;
}