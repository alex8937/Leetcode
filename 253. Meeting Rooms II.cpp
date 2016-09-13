/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
struct comp_q{
    bool operator()(const Interval& p,const Interval& q) {
        return p.end > q.end;
    }
};

class Solution {
public:
    static bool comp(const Interval& p,const Interval& q) {
        return p.start < q.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
    //version 1: map O(NlgN)
        map<int,int> dict;
        for(auto it : intervals) {
            dict[it.start]++;   //map[] take O(lgN)
            dict[it.end]--;            
        }
        int ans = 0, i = 0;
        for(auto it = dict.begin(); it != dict.end(); ++it) {
            i += it -> second;
            ans = max(ans, i);
        }
        return ans;
     //version 2: priority_queue    O(NlgN)   
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<Interval, vector<Interval>, comp_q> inter_queue;
        int ans = 0;
        for(int i = 0; i < intervals.size(); ++i) {
            while(!inter_queue.empty() && intervals[i].start >= inter_queue.top().end) {
                inter_queue.pop();
            }
            inter_queue.push(intervals[i]);
            ans = max(ans, int(inter_queue.size()));
        }
        return ans;
        
        
        
    }
};