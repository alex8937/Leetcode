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
    static bool cmp(const Interval& p, const Interval& q) {
        return p.start < q.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 0; i < intervals.size(); ++i) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            while(i + 1 < intervals.size() && end >= intervals[i + 1].start) {
                end = max(end, intervals[i + 1].end);
                i++;
            }
            ans.emplace_back(Interval(start, end));
        }
        return ans;
    }
};