//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end)
        {
            int mid = start + (end-start) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[start] == nums[mid]) && (nums[end] == nums[mid]))
            {
                start++;
                end--;
            }
			// first half
			// first half is in order
            else if(nums[start] <= nums[mid])
            {
				// target is in first  half
                if((nums[start] <= target) && (nums[mid] > target))
                    end = mid - 1;
                else
                    start = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[end]>= target))
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
	// for github repository link go to my profile.
};
