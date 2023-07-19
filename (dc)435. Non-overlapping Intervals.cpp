//https://leetcode.com/problems/non-overlapping-intervals/description/
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){ //The function first sorts the intervals based on their end times in ascending order using the custom comparator cmp.
//This sorting is crucial because it allows us to prioritize intervals that finish early.
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
//The function initializes two variables, prev and count. The prev variable is used to keep track of the index of the last processed interval, and count is used to store the number of non-overlapping meetings found so far. 
//We start count with 1 because the first interval is considered non-overlapping with itself.
        int prev = 0;
        int count = 1;

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){//The function uses a greedy approach to find the maximum number of non-overlapping meetings.
                prev = i;
                count++;
            }
        }//For each interval at index i, it checks if the start time of the current interval (intervals[i][0]) is greater than or equal to the end time of the previous interval (intervals[prev][1]).
//If this condition is true, it means the current interval does not overlap with the previous one, and we can safely attend this meeting. 
//In that case, we update prev to the current index i and increment count to reflect that we have attended one more meeting
        return n - count;
    }
};
//Finally, the function returns the number of intervals that need to be removed to make the remaining intervals non-overlapping. 
//Since we want to maximize the number of meetings we can attend, this value is calculated as n - count, where n is the total number of intervals.
