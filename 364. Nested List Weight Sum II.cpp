class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> sums;
        helper(nestedList, sums, 0);
        int ans = 0, len = sums.size();
        for(int i = 0; i < sums.size(); ++i) {
            ans += sums[i] * (len - i);
        }
        return ans;
    }
    
    void helper(vector<NestedInteger>& nestedList, vector<int>& sums, int level) {
        if(sums.size() == level) sums.push_back(0);
        for(auto it : nestedList) {
            if(it.isInteger()) {
                sums[level] += it.getInteger();
            }
            else {
                helper(it.getList(), sums, level + 1);
            }
        }
    }
};



class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ans = 0, acc = 0;
        while(!nestedList.empty()) {
            vector<NestedInteger> next;
            for(auto it : nestedList) {
                if(it.isInteger()) {
                    acc += it.getInteger();
                }
                else {
                    auto to_add = it.getList();
                    next.insert(next.end(), to_add.begin(), to_add.end());
                }
            }
            ans += acc;
            swap(nestedList, next);
        }
        return ans;
    }
};