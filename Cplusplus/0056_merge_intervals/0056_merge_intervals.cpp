/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0)
            return result;
        sort(intervals.begin(),  intervals.end(), compare);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i + 1].start <= end)
                end = max(end, intervals[i + 1].end);
            else {
                Interval temp = Interval(start, end);
                result.push_back(temp);
                start = intervals[i + 1].start;
                end = intervals[i + 1].end;
            }
        }
        Interval temp = Interval(start, end);
        result.push_back(temp);
        return result;
    }
    
    static bool compare(const Interval &a, const Interval &b){
        return a.start < b.start;
    }
};