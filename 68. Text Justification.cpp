class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int end = 0;
        vector<string> ans;
        while(end < words.size()) {
            int start = end, accu = 0;
            while(end < words.size() && accu <= maxWidth) {
                if(accu != 0) accu++;
                accu += words[end++].size();
            }
            if(accu > maxWidth) {
                accu -= words[--end].size() + 1;
            }
            string dummy;
            int num = end - start;
            if(num == 1 || end == words.size()) {
                for(int i = start; i < end; ++i) {
                    if(!dummy.empty()) dummy += " ";
                    dummy += words[i];
                }
                dummy += string(maxWidth - accu, ' ');
            }
            else {
                int reminder = (maxWidth - accu) % (num - 1);
                int base = (maxWidth - accu) / (num - 1);
                for(int i = start; i < end; ++i) {
                    if(!dummy.empty()) dummy += string(base + 1 + ((reminder-- > 0)? 1 : 0), ' ');
                    dummy += words[i];
                }
            }
            ans.emplace_back(dummy);
        }
        return ans;
    }
};