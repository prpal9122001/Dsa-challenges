//https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/?envType=study-plan&id=programming-skills-i

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double ans=0;
        sort(salary.begin(),salary.end());
        for(int i=1;i<n-1;i++){
            ans+=salary[i];
        }
        return ans/(n-2);
    }
};
