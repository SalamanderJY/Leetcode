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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(root, sum, res, curr);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> curr) {
        if (root == NULL)
            return;
        if (root->val == sum && root->right == NULL && root->left == NULL) {
            curr.push_back(root->val);
            res.push_back(curr);
            return;
        }
        curr.push_back(root->val);
        dfs(root->left, sum - root->val, res, curr);
        dfs(root->right, sum - root->val, res, curr);
    }
};