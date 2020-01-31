class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        length = len(nums1) + len(nums2)
        
        if length % 2 == 0:
            return (self.findKth(nums1, nums2, 0, len(nums1), 0, len(nums2), length // 2) + self.findKth(nums1, nums2, 0, len(nums1), 0, len(nums2), length // 2 + 1)) / 2.0
        else:
            return self.findKth(nums1, nums2, 0, len(nums1), 0, len(nums2), length // 2 + 1)
    
    def findKth(self, nums1, nums2, start1, len1, start2, len2, k):
        if len1 > len2:
            return self.findKth(nums2, nums1, start2, len2, start1, len1, k)
        
        if len1 == 0:
            return nums2[start2 + k - 1]
        
        if k == 1:
            return min(nums1[start1], nums2[start2])
        
        p1 = min(k // 2, len1)
        p2 = k - p1
        if nums1[start1 + p1 - 1] > nums2[start2 + p2 - 1]:
            return self.findKth(nums1, nums2, start1, len1, start2 + p2, len2 - p2, k - p2)
        elif nums1[start1 + p1 - 1] < nums2[start2 + p2 - 1]:
            return self.findKth(nums1, nums2, start1 + p1, len1 - p1, start2, p2, k - p1)
        else:
            return nums1[start1 + p1 - 1]