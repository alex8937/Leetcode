class TwoSum {
private: 
    unordered_map<int, int> dict;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        dict[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) { 
        for(auto it : dict) {
            int num = it.first;
            int target = value - num;
            if(target == num && dict[target] >= 2) {
                return true;
            }
            else if(target != num && dict.count(target)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */