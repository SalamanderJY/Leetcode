/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<TreeNode> level = new ArrayList<TreeNode>();
        level.add(root);
        while (root != null && level.size() > 0)
		{
			List<Integer> cur_level = new ArrayList<Integer>();
			for (int i = 0; i < level.size(); i++)
				cur_level.add(level.get(i).val);
			if (cur_level.size() > 0)
				result.add(cur_level);

			List<TreeNode> next_level = new ArrayList<TreeNode>();
			for (int i = 0; i < level.size(); i++)
			{
				if (level.get(i).left != null)
					next_level.add(level.get(i).left);
				if (level.get(i).right != null)
					next_level.add(level.get(i).right);
			}
			level = next_level;
		}
        
        List<List<Integer>> temp = new ArrayList<List<Integer>>();
        for (int i = 0; i < result.size(); i++) {
            temp.add(result.get(result.size() - i - 1));
        }
        
		return temp;
    }
}