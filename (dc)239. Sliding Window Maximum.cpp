// Link: https://leetcode.com/problems/sliding-window-maximum/description/
class Solution {
    using int2 = pair<int, int>; // (nums[i], i)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int2> pq; // Priority queue to maintain the maximum element and its index in the window

        vector<int> ans(n - k + 1); // Vector to store the maximum elements for each window
        for (int i = 0; i < k; i++)
            pq.push({nums[i], i}); // Push the first k elements with their indices into the priority queue

        ans[0] = pq.top().first; // Store the maximum element of the first window

        for (int i = k; i < n; i++) {
            while (!pq.empty() && pq.top().second <= (i - k))
                pq.pop(); // Pop up element not in the current window

            pq.push({nums[i], i}); // Push the current element into the priority queue
            ans[i - k + 1] = pq.top().first; // Store the maximum element for the current window
        }
        return ans;
    }
};
