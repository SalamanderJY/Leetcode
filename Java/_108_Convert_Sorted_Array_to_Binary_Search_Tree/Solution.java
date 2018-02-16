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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length <= 0)
			return null;
		else {
			TreeNode root = new TreeNode(nums[nums.length / 2]);
			int[] left_nums = Arrays.copyOfRange(nums, 0, nums.length / 2);
			int[] right_nums = Arrays.copyOfRange(nums, nums.length / 2 + 1, nums.length);
			root.left = sortedArrayToBST(left_nums);
			root.right = sortedArrayToBST(right_nums);
			return root;
		}
    }
}