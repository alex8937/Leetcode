//version 1: quick seletion
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, 0, nums.size() - 1, k);
    }
    int find(vector<int>& nums, int start, int end, int k) {
        if(start == end) return nums[start];
        random_shuffle(nums.begin() + start, nums.begin() + end + 1);
        int pivot = nums[start];
        int left = start + 1, right = end;
        while(left <= right) {
            while(left <= right && nums[left] >= pivot) left++;
            while(left <= right && nums[right] < pivot) right--;
            if(left <= right) swap(nums[left++], nums[right--]);
        }
        swap(nums[start], nums[right]);
        int leftnum = right - start;
        if(leftnum == k - 1) return nums[right];
        else if(leftnum > k - 1) return find(nums, start, right - 1, k);
        else return find(nums, right + 1, end, k - leftnum - 1);
    }
};
//version 2: min heap
struct cmp{
    bool operator()(const int& p, const int& q) {
        return p > q;
    }    
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp> pq;
        for(int n : nums) {
            if(pq.size() < k) {
                pq.push(n);
            }
            else {
                if(n > pq.top()) {
                    pq.pop();
                    pq.push(n);
                }
            }
        }
        return pq.top();
    }
};