//https://leetcode.com/problems/number-of-music-playlists/description/
class Solution {
public:
 
    const int MOD=1e9+7;
    long long solve(int n, int goal, int k,vector<vector<int>>&dp){
        //base case
            if(n==0 && goal==0){
                return 1;
            }else if(n==0 || goal==0){
                return 0;
            }else if(dp[n][goal]!=-1)//If the value of dp[n][goal] is already calculated (not equal to -1).This is the memoization step to avoid redundant calculations.
            return dp[n][goal];
            long long pick=solve(n-1,goal-1,k,dp)*n;//There are n choices for the first position, n - 1 for the second, and so on.
      //So, we multiply solve(n - 1, goal - 1, k, dp) by n to count all valid playlists when we pick a song for the current position.
            long long notpick=solve(n,goal-1,k,dp)*max(n-k,0);//We do not choose a song for the current position. 
    //In this case, we can select any song from the remaining max(n - k, 0) songs (to ensure there are at least k songs between repeated songs). 
      //So, we multiply solve(n, goal - 1, k, dp) by max(n - k, 0)
            return dp[n][goal]=(pick+notpick)%MOD;
        }
     int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        return solve(n,goal,k,dp);
    }
};
