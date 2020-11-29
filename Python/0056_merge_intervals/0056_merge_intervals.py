# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) == 0:
            return []
        intervals = sorted(intervals,  key=lambda interval: interval.start)
        start = intervals[0].start
        end = intervals[0].end
        result = []
        for i in range(len(intervals) - 1):
            if intervals[i + 1].start <= end:
                end = max(end, intervals[i + 1].end)
            else:
                temp = Interval(start, end)
                result.append(temp)
                start = intervals[i + 1].start
                end = intervals[i + 1].end
        temp = Interval(start, end)
        result.append(temp)
        return result
