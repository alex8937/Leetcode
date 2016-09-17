class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0);
        vector<int> ugly = {1};
        while(ugly.size() < n) {
            int next = INT_MAX;
            for(int i = 0; i < index.size(); ++i) {
                next = min(next, ugly[index[i]] * primes[i]);
            }
            ugly.push_back(next);
            for(int i = 0; i < index.size(); ++i) {
                if(ugly[index[i]] * primes[i] == next) index[i]++;
            }
        }
        return ugly.back();
    }
};