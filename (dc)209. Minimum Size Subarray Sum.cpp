//https://leetcode.com/problems/minimum-size-subarray-sum/description/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long int sum=0,sum2=0;
        int m=INT_MAX,j=0,i=0;
        int n=nums.size();
        while(i<n){
            if(sum<target){
                sum+=nums[i++];
            }
            if(sum==target){
                m=min(m,i-j);
                sum+=nums[i++];
            }
            while(sum>=target && j<n){
                m=min(m,i-j);
                sum-=nums[j++];
            }
        }
        if(m==INT_MAX){return 0;}
        return m;
    }
};
