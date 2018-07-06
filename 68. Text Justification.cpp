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

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while(i < words.size()) {
            int k = 0, len = 0;
            while(i + k < words.size() && len + words[i + k].size() <= maxWidth - k) {
                len += words[i + k].size();
                k++;
            }
            string temp = words[i];
            for(int j = 0; j < k - 1; ++j) {
                if(i + k == words.size()) temp.push_back(' ');
                else {
                    string spaces((maxWidth - len) / (k - 1) + (j < (maxWidth - len) % (k - 1)), ' ');
                    temp.append(spaces);
                }
                temp.append(words[i + j + 1]);
            }
            temp.append(string(maxWidth - temp.size(), ' '));
            ans.push_back(temp);
            i += k;
        }
        return ans;
    }
};