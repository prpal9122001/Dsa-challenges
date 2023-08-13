//https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector
        if (n == 1) return false; // If there is only one element, return false (no valid partition)

        // Initialize a vector dp to keep track of the valid partitions
        // dp[0] represents whether a valid partition ends at the current index with a single element
        // dp[1] represents whether a valid partition ends at the current index with two consecutive equal elements
        // dp[2] represents whether a valid partition ends at the current index with three consecutive equal elements
        vector<bool> dp = {true, false, n > 1 ? nums[0] == nums[1] : false};

        // Loop through the array starting from the third element
        for (int i = 2; i < n; i++) {
            // Calculate whether the current index contributes to a valid partition
            bool current_dp = (nums[i] == nums[i-1] && dp[1]) || 
                              (nums[i] == nums[i-1] && nums[i] == nums[i-2] && dp[0]) ||
                              (nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1 && dp[0]);

            // Shift the values in dp to update for the current index
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = current_dp;
        }

        // Return whether a valid partition with three consecutive equal elements exists
        return dp[2];
    }
};
