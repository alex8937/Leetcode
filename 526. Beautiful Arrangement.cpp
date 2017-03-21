class Solution {
public:
    int countArrangement(int N) {
	// version 1: using used boolean vector
        vector<bool> used(N, false);
        int cnt = 0;
        help(cnt, used, 1);
        return cnt;
    }
    void help(int& cnt, vector<bool>& used, int pos) {
        if(pos > used.size()) {
            cnt++;
            return;
        }
        for(int i = 1; i <= used.size(); ++i) {
            if(!used[i - 1] && (pos % i == 0 || i % pos == 0)) {
                used[i - 1] = true;
                help(cnt, used, pos + 1);
                used[i - 1] = false;
            }
        }
    }
};

class Solution {
public:
    int countArrangement(int N) {
	// version 1: using integer to serves as the boolean vector
        int cnt = 0, used = 0;
        help(cnt, used, 1, N);
        return cnt;
    }
    void help(int& cnt, int& used, int pos, const int& total) {
        if(pos > total) {
            cnt++;
            return;
        }
        for(int i = 1; i <= total; ++i) {
            int mask = 1 << (i - 1);
            if(!(used & mask) && (pos % i == 0 || i % pos == 0)) {
                used |= mask;
                help(cnt, used, pos + 1, total);
                used = ~(~used | mask); // set certain bit to be zero
            }
        }
    }
};

class Solution {
public:
    int countArrangement(int N) {
	// version 2: using swap function
	// note that going from end to begin in the array can drastically speed up the computation
        vector<int> nums;
        for(int i = 1; i <= N; ++i) {
            nums.push_back(i);
        }
        return help(nums, N - 1);
    }
    int help(vector<int>& nums, int start) {
        if(start == -1) {
            return 1;
        }
        int ans = 0;
        for(int i = start; i >= 0; --i) {
            if(nums[i] % (start + 1) == 0 || (start + 1) % nums[i] == 0) {
                swap(nums[i], nums[start]);
                ans += help(nums, start - 1);
                swap(nums[i], nums[start]);
            }
        }
        return ans;
    }
};