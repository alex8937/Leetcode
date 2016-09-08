/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return sum_helper(nestedList, 1);
    }
    
    int sum_helper(vector<NestedInteger>& nestedList, int dep) {
        int sum = 0;
        for(auto it : nestedList) {
            if(it.isInteger()) {
                sum += it.getInteger() * dep;
            }
            else {
                sum += sum_helper(it.getList(), dep + 1);
            }
        }
        return sum;
    }
};