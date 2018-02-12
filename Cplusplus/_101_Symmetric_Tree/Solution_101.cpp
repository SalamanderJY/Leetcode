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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        else return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;      
        else if(p == NULL || q == NULL)
            return false;
        else if(p->val != q->val)
            return false;
        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};