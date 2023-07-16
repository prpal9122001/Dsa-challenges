//https://leetcode.com/problems/smallest-sufficient-team/description/
class Solution {
public:
    vector<int> res; // The final result vector to store the indices of people with the smallest sufficient team.

    // Recursive helper function to find the smallest sufficient team.
    void helper(int i, vector<int>& people_skill, int m, int mask, vector<int>& ans, vector<vector<int>>& dp) {
        if (i == people_skill.size()) { // Base Case: If all people are considered.
            if (mask == ((1 << m) - 1)) { // Check if all required skills are covered in the team.
                if (res.size() == 0 || (ans.size() < res.size())) // If no result is found yet or the current team size is smaller than the stored result.
                    res = ans; // Update the result vector.
            }
            return; // Return to previous recursion level.
        }

        if (dp[i][mask] != -1) { // Memoization Part: Check if the current state (i, mask) has already been calculated before.
            if (dp[i][mask] <= ans.size()) // If the previous result size is smaller or equal to the current team size.
                return; // No need to explore this state, return to previous recursion level.
        }

        helper(i + 1, people_skill, m, mask, ans, dp); // Non-Pick / Ignore Case: Skip the current person.

        ans.push_back(i); // Pick Case: Add the current person to the team.

        helper(i + 1, people_skill, m, (mask | people_skill[i]), ans, dp); // Recurse for the next person with updated skill mask.

        ans.pop_back(); // Undo the change in Pick: Remove the current person from the team.

        if (ans.size() > 0) // If a valid team is found (non-empty ans vector).
            dp[i][mask] = ans.size(); // Store the size of the team for this state (i, mask) in the DP table.
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size(); // Number of people
        int m = req_skills.size(); // Number of required skills

        unordered_map<string, int> mpp; // Hash map to map skill names to their corresponding bit masks.

        for (int i = 0; i < m; ++i)
            mpp[req_skills[i]] = (1 << i); // Set the ith bit to 1 for the required skill 'req_skills[i]'.

        vector<int> people_skill; // Vector to store the bit masks of skills possessed by each person.

        for (auto it : people) {
            int mask = 0;
            for (int j = 0; j < it.size(); ++j) {
                if (mpp.count(it[j])) // If the skill 'it[j]' is a required skill.
                    mask |= mpp[it[j]]; // Set the corresponding bit in the mask.
            }
            people_skill.push_back(mask); // Store the person's skill mask.
        }

        vector<vector<int>> dp(n, vector<int>((1 << m), -1)); // DP table to store the results for each state.

        vector<int> ans; // Vector to store the current team during recursion.

        helper(0, people_skill, m, 0, ans, dp); // Call the helper function to find the smallest sufficient team.

        return res; // Return the result vector with the indices of people in the smallest sufficient team.
    }
};
