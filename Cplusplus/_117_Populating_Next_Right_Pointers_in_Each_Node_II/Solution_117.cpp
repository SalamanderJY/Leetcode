/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* tmpRoot = root;    
        while (tmpRoot != NULL) {
            TreeLinkNode* cur = tmpRoot;
            TreeLinkNode* dummy = new TreeLinkNode(0);
            TreeLinkNode* tmp = dummy;

            while (cur != NULL) {
                if (cur->left != NULL) {
                    tmp->next = cur->left;
                    tmp = tmp->next;
                }
                if (cur->right != NULL) {
                    tmp->next = cur->right;
                    tmp = tmp->next;
                }
                cur = cur->next;
            }          
            tmpRoot = dummy->next;
        }
    }
};