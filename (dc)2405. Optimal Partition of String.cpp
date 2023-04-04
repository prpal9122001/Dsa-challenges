//https://leetcode.com/problems/optimal-partition-of-string/submissions/

class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
vector<int>
        int count = 1, substringStart = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s[i] - 'a'] >= substringStart) {
                count++;
                substringStart = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }
        return count;
    }
};
