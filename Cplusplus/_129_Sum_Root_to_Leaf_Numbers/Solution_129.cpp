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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int res) {
        if (root == NULL)
            return 0;
        res = 10 * res + root->val;
        if (root->left == NULL && root->right == NULL)
            return res;
        return dfs(root->left, res) + dfs(root->right, res);
    }
};