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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
		vector<TreeNode*> level;
		level.push_back(root);
        int level_num = 1;
		while (root != NULL && level.size() > 0)
		{
            vector<int> cur_level;
			for (int i = 0; i < level.size(); i++)
				cur_level.push_back(level.at(i)->val);
			if (cur_level.size() > 0 && level_num % 2 == 1)
				result.push_back(cur_level);
            if (cur_level.size() > 0 && level_num % 2 == 0) {
                reverse(cur_level.begin(), cur_level.end());
                result.push_back(cur_level);
            }
            
			vector<TreeNode*> next_level;
			for (int i = 0; i < level.size(); i++)
			{
				if (level.at(i)->left != NULL)
					next_level.push_back(level.at(i)->left);
				if (level.at(i)->right != NULL)
					next_level.push_back(level.at(i)->right);
			}
			level = next_level;
            level_num++;
		}
		return result;
    }
};