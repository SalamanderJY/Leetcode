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
    int sum = 0;
    
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root, false);
        return sum;
    }
    
    void helper(TreeNode* root, bool isLeft) {
        if (root == NULL) return;
        if (isLeft == true && root->left == NULL && root->right == NULL) 
            sum += root->val;
        helper(root->left, true);
        helper(root->right, false);
    }
};
