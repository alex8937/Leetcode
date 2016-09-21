class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        // First index s.t. citations[index] >= len - index => H = len - index
        int len = citations.size();
        int start = 0, end = len; // maxH = len - 0 = len, minH = len - len = 0
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(citations[mid] >= len - mid) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return len - start;
        
    }
};