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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
        {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            return min(left, right) ? min(left, right) + 1 : max(left, right) + 1;
        }
    }
};