//https://leetcode.com/problems/total-cost-to-hire-k-workers/description/
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i = 0;
        int j = costs.size() - 1;//Two integer variables i and j are initialized to track the start and end indices of the costs vector, respectively. 
      //These indices will be used to iterate over the vector.
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;//Two priority queues, pq1 and pq2, are created. 
      //Priority queues are data structures that allow efficient insertion and retrieval of elements while maintaining a specific order. 
      //In this case, the elements are integers, and the order is ascending (greater<int>).

        long long ans = 0;//A long long variable ans is initialized to store the total cost.
        while(k--){ //The code enters a loop that executes k times, where k is the number of workers to be hired.
            while(pq1.size() < candidates && i <= j){
                pq1.push(costs[i++]);
            }
            while(pq2.size() < candidates && i <= j){
                pq2.push(costs[j--]);
            }//Inside the loop, two nested while loops are used to populate pq1 and pq2 with candidates from the costs vector. 
          //The conditions for these loops are as follows:pq1 should contain at most candidates elements, and i should be less than or equal to
          //j.pq2 should also contain at most candidates elements, and i should be less than or equal to j.
          //These loops essentially fill the priority queues with the smallest candidates elements from the costs vector, taking elements from both ends of the vector (i and j).

            int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;//After the while loops, the code compares the top elements (t1 and t2) of pq1 and pq2 to determine which one is smaller. 
          //If both queues are empty, INT_MAX (maximum value for an int) is used as a placeholder.

            if(t1 <= t2){
                ans += t1;
                pq1.pop();
            }
            else{
                ans += t2;
                pq2.pop();
            }//If t1 is smaller than or equal to t2, the cost of the worker represented by t1 is added to ans, and the top element is removed from pq1 using pq1.pop(). 
          //Otherwise, the cost of the worker represented by t2 is added to ans, and the top element is removed from pq2 using pq2.pop().
        }
        return ans;//The loop continues until k workers have been hired.Finally, the function returns the accumulated total cost (ans).
    }
};
