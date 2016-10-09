class Solution {
public:
	//version1: set		O(nlogk)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> window;		
        for(int i = 0; i < nums.size(); ++i) {
            if(i > k) window.erase(nums[i - k - 1]); // erase the one left beyound the window
            auto pos = window.lower_bound(nums[i] - t);
						
			//   a1, a2, .........[ ......ax....... aj] aj+1
			//														|
			//														aj+1 - t  ==> ax >= aj+1 - t
			// 	if 																			ax <= aj+1 + t  ==> true
			
            if(pos != window.end() && *pos <= long(nums[i] + long(t)) return true;
            window.insert(nums[i]);
        }
        return false;
    }
	//version2: Bucket		O(n)		
    inline long f(long n, long t) {
        return (n - INT_MIN) / (t + 1);  //Bucket size to be t + 1, which handles t = 0;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0) return false;
        unordered_map<long, long> dict;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > k) dict.erase(f(nums[i - k - 1], t));
            long index = f(nums[i], t);
            if(dict.count(index)) return true;
            if(dict.count(index - 1) && nums[i] - dict[index - 1] <= t) return true;
            if(dict.count(index + 1) && dict[index + 1] - nums[i] <= t) return true;
            dict[index] = nums[i];
        }
        return false;
    }
};