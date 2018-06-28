class RandomizedSet {
private:
    unordered_map<int, int> dict;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.count(val)) return false;
        nums.push_back(val);
        dict[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!dict.count(val)) return false;
        swap(nums.back(), nums[dict[val]]);
        dict[nums[dict[val]]] = dict[val];
        dict.erase(val);
        nums.pop_back();   
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        random_device rd;
        uniform_int_distribution<int> dist(0, int(nums.size()) - 1);
        return nums[dist(rd)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */