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

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int it = 0;
        for(; it < intervals.size(); ++it) {
            if(newInterval.start < intervals[it].start) break;
        }
        intervals.insert(intervals.begin() + it, newInterval);
        vector<Interval> ans;
        for(int i = 0; i < intervals.size(); ++i) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            while(i + 1 < intervals.size() && intervals[i + 1].start <= end) {
                end = max(end, intervals[i + 1].end);
                i++;
            }
            ans.emplace_back(start, end);
        }
        return ans;
    }
};


class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> left, right;
        int start = newInterval.start, end = newInterval.end;
        for(auto it : intervals) {
            if(it.end < start) {
                left.push_back(it);
            }
            else if(it.start > end) {
                right.push_back(it);
            }
            else {
                start = min(start, it.start);
                end = max(end, it.end);
            }
        }
        left.emplace_back(start, end);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};