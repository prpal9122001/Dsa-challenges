//https://leetcode.com/problems/counting-bits/description/?envType=daily-question&envId=2023-09-01
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0); // Initialize a vector to store the counts
        for (int i = 1; i <= n; i++) {
            // The number of set bits in i can be obtained by right-shifting and counting the least significant bit
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
