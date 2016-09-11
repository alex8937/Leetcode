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
    static bool comp(const Interval& int1, const Interval& int2) {  // Comparator need to be static
        return (int1.start) < (int2.start); // order: int1, int2
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start < intervals[i - 1].end) return false;
        }
        return true;
        
    }
};