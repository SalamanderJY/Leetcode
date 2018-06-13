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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd || preStart > preEnd)
            return NULL;
        int rootVal = preorder[preStart];
        int rootIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        int len = rootIndex - inStart;
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(preorder, preStart + 1, preStart + len, inorder, inStart, rootIndex - 1);
        root->right = buildTree(preorder, preStart + len + 1, preEnd, inorder, rootIndex + 1, inEnd);
        
        return root;
    }
};
