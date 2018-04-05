class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> mapping = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums2.length; i++)
        {
            for (int j = i; j < nums2.length; j++)
            {
                if (nums2[j] > nums2[i])
                {
                    mapping.put(nums2[i], nums2[j]);
                    break;
                }
                if (j == nums2.length - 1)
                    mapping.put(nums2[i], -1);
            }
        }       
        int[] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++)
            res[i] = mapping.get(nums1[i]);
        return res;
    }
}