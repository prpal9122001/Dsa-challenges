//https://leetcode.com/problems/combinations/description/
class Solution {
public:
vector<vector<int>>ans;
void helper(int idx,int k,vector<int>&current,int n){
     if(current.size()==k)
     {
          ans.push_back(current);
          return;
     }
     for(int i=idx;i<n+1;i++)
     {
          current.push_back(i);//i is current element
          helper(i+1,k,current,n);//generate combinations
          current.pop_back();//proceed to next elemnet
     }
  }
    vector<vector<int>> combine(int n, int k) {
         vector<int>current;
         helper(1,k,current,n);
         return ans;  //return ans   
    }
};

//The base case of the recursive function is when the current combination size is equal to k, in which case it is added to the answer vector.
//The main function initializes an empty current vector and calls the helper function with the first index and the given values for n and k, returning the answer vector once the function completes. 
//The output of the program is a vector of all possible combinations of size k from 1 to n.
