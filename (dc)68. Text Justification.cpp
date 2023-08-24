//https://leetcode.com/problems/text-justification/description/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        
        for(int i = 0, w; i < n; i = w) {       
           int len = -1; 
            for(w = i; w < n && len + words[w].length() + 1 <= maxWidth; w++) {
                len += words[w].length() + 1;
            }
            string str = words[i];
            int space = 1, extra = 0;
            if(w != i + 1 && w != words.size()) { 
                space = (maxWidth - len) / (w - i - 1) + 1;
                extra = (maxWidth - len) % (w - i - 1);
            }
            for(int j = i + 1; j < w; ++j) {
                for(int s = space; s > 0; s--) str += ' ';
                if(extra-- > 0) str += ' ';
                str += words[j];
            }
        
            int strLen = maxWidth - str.length();
            while(strLen-- > 0) str += ' ';
            ans.push_back(str);
        }
        return ans;
    }
};
