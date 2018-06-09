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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n < 1)
            return res;
        return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int left, int right) {
        vector<TreeNode*> res;
        if (left > right) {
            res.push_back(NULL);
            return res;
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftList = generateTrees(left, i - 1);
            vector<TreeNode*> rightList = generateTrees(i + 1, right);
            for (int j = 0; j < leftList.size(); j++) {
                for (int k = 0; k < rightList.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftList[j];
                    root->right = rightList[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};