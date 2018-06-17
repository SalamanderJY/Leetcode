/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        int size = 0;
        ListNode temp = head;
        while (temp != null) {
            ++size;
            temp = temp.next;
        }
        int[] tree = new int[size];
        int i = 0;
        while (head != null) {
            tree[i] = head.val;
            head = head.next;
            ++i;
        }
        TreeNode root = sortedArrayToBST(tree);     
        return root;
    }
    
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