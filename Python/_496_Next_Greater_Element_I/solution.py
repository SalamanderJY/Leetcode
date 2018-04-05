class Solution:
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        mapping = {}
        for i in range(len(nums2)):
            for j in range(i, len(nums2)):
                if nums2[j] > nums2[i]:
                    mapping[nums2[i]] = nums2[j]
                    break
                if j == len(nums2) - 1:
                    mapping[nums2[i]] = -1
        res = []
        for i in range(len(nums1)):
            res.append(mapping[nums1[i]])
        return res
