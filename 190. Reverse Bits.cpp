class Solution {
public:
	// version1: bit by bit
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; ++i) {
            ans <<= 1;
            ans += (n & 1);
            n >>= 1;            
        }
        return ans;
    }
};

class Solution {
public:
	// 4 bits by 4 bits
    uint32_t reverseBits(uint32_t n) {
        vector<int> dict = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
        uint32_t ans = 0;
        for(int i = 0; i < 8; i++) {
            ans <<= 4;
            ans |= dict[0xf & n];
            n >>= 4;
        }
        return ans;        
    }
};