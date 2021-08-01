/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NODE_NUM    1024

void dfs(struct TreeNode* root, int *res, int *index)
{
    if (root == NULL) {
        return;
    }
    dfs(root->left, res, index);
    res[(*index)++] = root->val;
    dfs(root->right, res, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *res = (int *)malloc(sizeof(int) * NODE_NUM);
    *returnSize = 0;
    dfs(root, res, returnSize);
    return res;
}