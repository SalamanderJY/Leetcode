class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        start = 0;
        end = len(numbers) - 1
        result = []
        if end < 0:
            return result
        while numbers[start] + numbers[end] != target and start < end:
            if numbers[start] + numbers[end] < target:
                start += 1
            else:
                end -= 1
        if not start < end:
            return result
        else:
            result.append(start + 1)
            result.append(end + 1)
            return result