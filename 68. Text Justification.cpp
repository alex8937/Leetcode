class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int end = 0, start = 0, accu = 0;
        vector<string> ans;
        while(end < words.size()) {
            while(end < words.size() && accu <= maxWidth) {
                if(accu != 0) accu++;
                accu += words[end++].size();
            }
            if(accu > maxWidth) {
                accu -= words[--end].size() + 1;
            }
            string dummy;
            int num = end - start - 1;
            if(end == words.size() || num == 0) {
                for(int i = start; i < end; ++i) {
                    if(!dummy.empty()) dummy += " ";
                    dummy += words[i];  
                }
                dummy += string(maxWidth - accu, ' ');
            }
            else {
                 
                for(int i = start; i < end; ++i) {
                    if(!dummy.empty()) {
                        int offset = (reminder-- > 0)? 1 : 0;
                        dummy += string(len + 1 + offset , ' ');
                    }
                    dummy += words[i];
                }
            }
            start = end;
            ans.push_back(dummy);
            accu = 0;
        }
        return ans;
    }
};