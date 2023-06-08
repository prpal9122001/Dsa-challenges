//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/966596770/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans(0);
        for(const vector<int>& row:grid)
        for(const int& i:row)
        if(i<0) ans++;
        return ans;
    }
};
