class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = 0;
        while(index < bits.size() - 1) {
            if(bits[index] == 0) index++;
            else index += 2;
        }
        return index == bits.size() - 1 and bits[index] == 0;
    }
};