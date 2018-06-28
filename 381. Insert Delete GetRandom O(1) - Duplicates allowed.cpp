class RandomizedCollection {
private:
    unordered_map<int, vector<int>> dict;
    vector<pair<int, int>> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ans = !dict.count(val);
        nums.emplace_back(val, dict[val].size());
        dict[val].push_back(nums.size() - 1);
  
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {   
        bool ans = dict.count(val);
        if(!ans) return ans;
        auto last = nums.back();
        dict[last.first][last.second] = dict[val].back();
		swap(nums.back(), nums[dict[val].back()]);
        dict[val].pop_back();                      
        if(dict[val].empty()) dict.erase(val);
        nums.pop_back();
        return ans;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        random_device rd;
        uniform_int_distribution<int> dist(0, nums.size() - 1);
        return nums[dist(rd)].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */