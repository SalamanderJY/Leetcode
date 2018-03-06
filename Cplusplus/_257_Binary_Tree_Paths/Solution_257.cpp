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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == NULL) return result;
        dfs(root, result, path);
        return result;
    }
    
    void dfs(TreeNode* root, vector<string> &result, string path) {
        if (root == NULL) return;
        path += (path.size() == 0 ? "" : "->") + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
            return;
        }
        dfs(root->left, result, path);
        dfs(root->right, result, path);
    }
};
