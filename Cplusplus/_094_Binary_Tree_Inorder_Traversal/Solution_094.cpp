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
    // Recursive Method
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         dfs(root, res);
//         return res;
//     }
    
//     void dfs(TreeNode* root, vector<int> &res) {
//         if (root == NULL)
//             return;
//         dfs(root->left, res);
//         res.push_back(root->val);
//         dfs(root->right, res);
//     }
    
    // Iterative Method
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while (!s.empty() || root != NULL) {
            while (root != NULL) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
