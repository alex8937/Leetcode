class Solution {
public:
    int thirdMax(vector<int>& nums) {
     //version 1: using minheap of size 3 with a set
        auto comp = [](int a, int b){return a > b;};
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        unordered_set<int> dict;
        for(int n : nums) {
            if(dict.count(n)) continue;
            if(!pq.empty() && pq.top() < n || pq.size() < 3) {
                pq.push(n);
                dict.insert(n);
            }
            if(pq.size() > 3) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return (ans.size() == 3)? ans[0] : ans.back();
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
      // version 2: one iteration 
        long first, second, third;
        first = second = third = LONG_MIN;
        for(long num : nums) {
            if(num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if(num > second && num < first) {
                third = second;
                second = num;
            }
            else if(num > third && num < second) {
                third = num;
            }
        }
        return (third == LONG_MIN)? first : third;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
      // version 3: one iteration using swap
        long first, second, third;
        first = second = third = LONG_MIN;
        for(long n : nums) {
            if(first < n) swap(n, first);
            if(n < first && n > second) swap(n, second);
            if(n < second && n > third) third = n;
        }
        return (third == LONG_MIN)? first : third;
    }
};



class Solution(object):
    def thirdMax(self, nums):
      // version 4: using divide and conquer
        def top3(nums):
            if len(nums) <= 3:
                return sorted(list(set(nums)))
            left = top3(nums[:len(nums) / 2])
            right = top3(nums[len(nums) / 2:])
            return sorted(list(set(left + right)))[-3:]
        ans = top3(nums)
        return ans[-3] if len(ans) == 3 else ans[-1]
            