//https://leetcode.com/problems/minimum-cost-for-tickets/submissions/
class Solution {
public:
    // we have option to buy ticket for only one day/ one week/ one month at every day;
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        
        // days[n-1] denotes the last day we want to travel
        vector<int> dp(days[n-1]+1,0);
        
        //dp[i] denotes minimum dollars required to travel till i days.
        dp[0]=0;
        
        map<int,int> mp;
        for(auto it: days){
            mp[it]++;
        }
        
        for(int i=1;i<=days[n-1];i++){
            // if we want to travel to ith day we need ticket 
            if(mp.count(i)==1){
                // 3 choices of tickets
                int month_ticket= dp[max(i-30,0)]+ costs[2];
                int week_ticket= dp[max(i-7,0)]+ costs[1];
                int day_ticket= dp[max(i-1,0)]+ costs[0];
                
                dp[i]= min(month_ticket,min( week_ticket, day_ticket));
            }
            else{
                //if we dont need to travel for ith day so dollar req = prev day dollar req
                dp[i]=dp[i-1];
            }
        }
        return dp[days[n-1]];
    }
};
