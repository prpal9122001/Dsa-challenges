//https://leetcode.com/problems/merge-strings-alternately/description/

class Solution {
public:
string mergeAlternately(string w1, string w2) {
    int i = 0, j = 0, sz1 = w1.size(), sz2 = w2.size();
    string res(sz1 + sz2, ' ');
    while (i < sz1 || j < sz2) {
        if (i < sz1)
            res[j + i++] = w1[i];
        if (j < sz2)
            res[i + j++] = w2[j];
    }
    return res;
}
};
