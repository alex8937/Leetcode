class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dict;
        for(auto& n : nums) {
            if(dict.count(n)) return true;
            dict.insert(n);
        }
        return false;
    }
};