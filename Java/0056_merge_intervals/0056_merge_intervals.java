/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        Collections.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        List<Interval> result = new ArrayList<Interval>();
        if (intervals.size() == 0)
            return result;
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals.get(i + 1).start <= end)
                end = Math.max(end, intervals.get(i + 1).end);
            else {
                Interval temp = new Interval(start, end);
                result.add(temp);
                start = intervals.get(i + 1).start;
                end = intervals.get(i + 1).end;
            }
        }
        Interval temp = new Interval(start, end);
        result.add(temp);
        return result;
    }
}