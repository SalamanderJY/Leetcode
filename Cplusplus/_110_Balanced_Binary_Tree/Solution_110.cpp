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
    bool balanced = true;
    
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return balanced;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
        {
            int leftDepth = maxDepth(root->left) + 1;
            int rightDepth = maxDepth(root->right) + 1;
            if (abs(leftDepth - rightDepth) > 1)
                balanced = false;
            return max(leftDepth, rightDepth);
        }
    }
};